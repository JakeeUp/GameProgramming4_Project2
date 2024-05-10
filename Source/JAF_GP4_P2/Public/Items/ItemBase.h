// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/ItemDataStruct.h"
#include "ItemBase.generated.h"

class AJAF_GP4_P2Character;
class UInventoryComponent;
/**
 * 
 */
UCLASS()
class JAF_GP4_P2_API UItemBase : public UObject
{
	GENERATED_BODY()

public:

	/**************************************************************
	***************************************************************
	 ******************* PROPERTIES AND VARIABLES ******************
	 ***************************************************************
	 *************************************************************/

	UPROPERTY()
	UInventoryComponent* OwningInventory;
	
	UPROPERTY(VisibleAnywhere, Category = "Item")
	int32 Quantity;
	
	UPROPERTY(VisibleAnywhere, Category = "Item")
	FName ID;

	UPROPERTY(VisibleAnywhere, Category = "Item")
	EItemType ItemType;

	UPROPERTY(VisibleAnywhere, Category = "Item")
	EItemQuality ItemQuality;

	UPROPERTY(VisibleAnywhere, Category = "Item")
	FItemStatistics ItemStatistics;

	UPROPERTY(VisibleAnywhere, Category = "Item")
	FItemTextData TextData;

	UPROPERTY(VisibleAnywhere, Category = "Item")
	FItemNumericData NumericData;

	UPROPERTY(VisibleAnywhere, Category = "Item")
	FItemAssetData AssetData;

	bool bIsCopy;
	bool bIsPickup;


	/**************************************************************
	***************************************************************
	 ******************* functions ******************
	 ***************************************************************
	 *************************************************************/

	UItemBase();

	void ResetItemFlags();

	UFUNCTION(Category = "Item")
	UItemBase* CreateItemCopy();

	UFUNCTION(Category = "Item")
	FORCEINLINE float GetItemStackWeight() const {return Quantity * NumericData.Weight;};

	UFUNCTION(Category = "Item")
	FORCEINLINE float GetItemSingleWeight() const {return NumericData.Weight; };
	
	UFUNCTION(Category = "Item")
	FORCEINLINE bool IsFullItemStack() const {return Quantity == NumericData.MaxStackSize; };

	UFUNCTION(Category = "Item")
	void SetQuantity(const int32 NewQuantity);

	UFUNCTION(Category = "Item")
	virtual void Use(AJAF_GP4_P2Character* Character);

protected:
	bool operator==(const FName& OtherID) const
	{
		return ID == OtherID;
	}
};
