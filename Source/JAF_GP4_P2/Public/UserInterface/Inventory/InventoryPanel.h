// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemSlot.h"
#include "Blueprint/UserWidget.h"
#include "JAF_GP4_P2/JAF_GP4_P2Character.h"
#include "InventoryPanel.generated.h"

class UWrapBox;
class UTextBlock;
/**
 * 
 */
UCLASS()
class JAF_GP4_P2_API UInventoryPanel : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void RefreshInventory();

	UPROPERTY(meta=(BindWidget))
	UWrapBox* InventoryPanel;
	UPROPERTY(meta=(BindWidget))
	UTextBlock* WeightInfo;
	UPROPERTY(meta=(BindWidget))
	UTextBlock* CapacityInfo;

	UPROPERTY()
	AJAF_GP4_P2Character* PlayerCharacter;
	UPROPERTY()
	UInventoryComponent* InventoryReference;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UInventoryItemSlot> InventorySlotClass;

protected:

	void SetInfoText() const;
	virtual void NativeOnInitialized() override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
		UDragDropOperation* InOperation) override;
};
