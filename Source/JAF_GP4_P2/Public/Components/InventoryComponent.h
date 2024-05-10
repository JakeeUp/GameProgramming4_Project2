// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


class UItemBase;

DECLARE_MULTICAST_DELEGATE(FOnInventoryUpdated);


UENUM(BlueprintType)
enum class EItemAddResult : uint8
{
	IAR_NoItemAdded UMETA(DisplayName = "NoItemAdded"),
	IAR_PartialAmountItemAdded UMETA(DisplayName = "Partial amount of item added"),
	IAR_AllItemAdded UMETA(DisplayName = "All of item added")
};

USTRUCT(BlueprintType)
struct FItemAddResult
{
	GENERATED_BODY()

	FItemAddResult() :
	ActualAmountAdded(0),
	OperationResult(EItemAddResult::IAR_NoItemAdded),
	ResultMessage(FText::GetEmpty())
	{};

	UPROPERTY(BlueprintReadOnly, Category = "Item Add Result")
	int32 ActualAmountAdded;
	UPROPERTY(BlueprintReadOnly, Category = "Item Add Result")
	EItemAddResult OperationResult;
	UPROPERTY(BlueprintReadOnly, Category = "Item Add Result")
	FText ResultMessage;

	static FItemAddResult AddedNone(const FText& ErrorText)
	{
		FItemAddResult AddedNoneResult;
		AddedNoneResult.ActualAmountAdded = 0;
		AddedNoneResult.OperationResult = EItemAddResult::IAR_NoItemAdded;
		AddedNoneResult.ResultMessage = ErrorText;
		return AddedNoneResult;
	};

	static FItemAddResult AddedPartial(const int32 PartialAmountAdded, const FText& ErrorText)
	{
		FItemAddResult AddedPartialResult;
		AddedPartialResult.ActualAmountAdded = 0;
		AddedPartialResult.OperationResult = EItemAddResult::IAR_NoItemAdded;
		AddedPartialResult.ResultMessage = ErrorText;
		return AddedPartialResult;
	};

	static FItemAddResult AddedAll(const int32 AmountAdded, const FText& Message)
	{
		FItemAddResult AddedAllResult;
		AddedAllResult.ActualAmountAdded = AmountAdded;
		AddedAllResult.OperationResult = EItemAddResult::IAR_NoItemAdded;
		AddedAllResult.ResultMessage = Message;
		return AddedAllResult;
	};
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class JAF_GP4_P2_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	//properties and variables
	FOnInventoryUpdated OnInventoryUpdated;
	//functions

	
	UInventoryComponent();

	UFUNCTION(Category = "Inventory")
	UItemBase* FindMatchingItem(UItemBase* ItemIn) const;
	
	UFUNCTION(Category = "Inventory")
	UItemBase* FindNextItemByID(UItemBase* ItemIn) const;
	
	UFUNCTION(Category = "Inventory")
	UItemBase* FindNextPartialStack(UItemBase* ItemIn) const;
	
	UFUNCTION(Category = "Inventory")
	FItemAddResult HandleAddItem(UItemBase* InputItem);
	
	UFUNCTION(Category = "Inventory")
	void RemoveSingleInstanceOfitem(UItemBase* ItemIn);

	UFUNCTION(Category = "Inventory")
	int32 RemoveAmountOfItem(UItemBase* ItemIn, int32 DesiredAmountToRemove);

	UFUNCTION(Category = "Inventory")
	void SplitExistingStack(UItemBase* ItemIn, const int32 AmountToSplit);

	//Getters
	// -----------------------------------------------------
	UFUNCTION(Category = "Inventory")
	FORCEINLINE float GetInventoryTotalWeight() const {return InventoryTotalWeight;};
	
	UFUNCTION(Category = "Inventory")
	FORCEINLINE float GetWeightCapacity() const {return InventoryWeightCapacity; };

	UFUNCTION(Category = "Inventory")
	FORCEINLINE int32 GetSlotsCapacity() const{return InventorySlotsCapacity;};

	UFUNCTION(Category = "Inventory")
	FORCEINLINE TArray<UItemBase*> GetInventoryContents() const {return InventoryContents;};

	//Setters
	//------------------------------------------

	UFUNCTION(Category = "Inventory")
	FORCEINLINE void SetSlotsCapacity(const int32 NewSlotsCapacity) {InventorySlotsCapacity = NewSlotsCapacity;};

	UFUNCTION(Category = "Inventory")
	FORCEINLINE void SetWeightCapacity(const float NewWeightCapacity){InventoryWeightCapacity = NewWeightCapacity; };

protected:

	//properties and variables
	UPROPERTY(EditInstanceOnly,Category = "Inventory")
	float InventoryTotalWeight;

	UPROPERTY(EditInstanceOnly, Category = "Inventory")
	int32 InventorySlotsCapacity;

	UPROPERTY(EditInstanceOnly, Category = "Inventory")
	float InventoryWeightCapacity;

	UPROPERTY(VisibleAnywhere, Category = "Inventory")
	TArray<TObjectPtr<UItemBase>> InventoryContents;
	
	//functions
	virtual void BeginPlay() override;

	FItemAddResult HandleNonStackableItems(UItemBase* ItemIn);
	int32 HandleStackableItem(UItemBase* ItemIn, int32 RequestedAddAmount);
	int32 CalculateWeightAddAmount(UItemBase* ItemIn, int32 RequestedAddAmount);
	int32 CalculateNumberForFullStack(UItemBase* ExistingItem, int32 InitialRequestedAddAmount);

	void AddNewItem(UItemBase* Item, const int32 AmountToAdd);


	
};
