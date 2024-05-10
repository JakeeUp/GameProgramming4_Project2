// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterface/MainMenu.h"
#include "UserInterface/Inventory/ItemDragDropOperation.h"
#include "Items/ItemBase.h"
#include "JAF_GP4_P2/JAF_GP4_P2Character.h"

void UMainMenu::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();
	PlayerCharacter = Cast<AJAF_GP4_P2Character>(GetOwningPlayerPawn());
}

bool UMainMenu::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
	UDragDropOperation* InOperation)
{
	const UItemDragDropOperation* ItemDragDrop = Cast<UItemDragDropOperation>(InOperation);

	if(PlayerCharacter && ItemDragDrop->SourceItem)
	{
		PlayerCharacter->DropItem(ItemDragDrop->SourceItem,ItemDragDrop->SourceItem->Quantity);
		return true;
	}
	return false;
}
