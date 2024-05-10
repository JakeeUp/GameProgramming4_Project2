// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/InteractableInterface.h"
#include "Items/ItemBase.h"
#include "Pickup.generated.h"

UCLASS()
class JAF_GP4_P2_API APickup : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:

	//Propperties and variables

	//functions
	virtual void BeginFocus() override;
	virtual void EndFocus() override;
	
	APickup();

	void InitializePickup(const TSubclassOf<UItemBase> BaseClass, const int32 InQuantity);

	void InitializeDrop(UItemBase* ItemToDrop, const int32 InQuantity);

	FORCEINLINE UItemBase* GetItemData() { return ItemReference; }

protected:
	//Propperties and variables
	UPROPERTY(VisibleAnywhere, Category = "Pickup | Components")
	UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditInstanceOnly, Category = "Pickup | Item Initialization")
	UDataTable* ItemDataTable;

	UPROPERTY(EditInstanceOnly, Category = "Pickup | Item Initialization")
	FName DesiredItemID;

	UPROPERTY(VisibleAnywhere, Category = "Pickup | Item Reference")
	UItemBase* ItemReference;

	UPROPERTY(EditInstanceOnly, Category = "Pickup | Item Initialization")
	int32 ItemQuantity;

	UPROPERTY(VisibleInstanceOnly, Category = "Pickup | Interaction")
	FInteractableData InstanceInteractableData;
	//functions
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void Interact(AJAF_GP4_P2Character* PlayerCharacter) override;


	void UpdateInteractableData();
	
	void TakePickup(const AJAF_GP4_P2Character* Taker);

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
};
