// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterface/Inventory/InventoryToolTip.h"

#include "Items/ItemBase.h"
#include "UserInterface/Inventory/InventoryItemSlot.h"
#include "Items/ItemBase.h"

void UInventoryToolTip::NativeConstruct()
{
	Super::NativeConstruct();

	const UItemBase* ItemBeingHovered = InventoryItemSlotBeingHovered->GetItemReference();

	switch (ItemBeingHovered->ItemType)
	{
	case EItemType::Armor:
		break;
	case EItemType::Weapon:
		break;
	case EItemType::Shield:
		break;
	case EItemType::Spell:
		break;
	case EItemType::Consumable:
		ItemType->SetText(FText::FromString("Consumable"));
		DamageValue->SetVisibility(ESlateVisibility::Collapsed);
		ArmorRating->SetVisibility(ESlateVisibility::Collapsed);
		//MaxStackSizeText->SetVisibility(ESlateVisibility::Collapsed);
		break;
	case EItemType::Quest:
		break;
	case EItemType::Random:
		ItemType->SetText(FText::FromString("Random"));
		DamageValue->SetVisibility(ESlateVisibility::Collapsed);
		ArmorRating->SetVisibility(ESlateVisibility::Collapsed);
		UsageText->SetVisibility(ESlateVisibility::Collapsed);
		MaxStackSizeText->SetVisibility(ESlateVisibility::Collapsed);
		break;
	default: ;
	}


	ItemName->SetText(ItemBeingHovered->TextData.Name);
	DamageValue->SetText(FText::AsNumber(ItemBeingHovered->ItemStatistics.DamageValue));
	ArmorRating->SetText(FText::AsNumber(ItemBeingHovered->ItemStatistics.ArmorRating));
	UsageText->SetText(ItemBeingHovered->TextData.UsageText);
	ItemDescription->SetText(ItemBeingHovered->TextData.Description);

	const FString WeightInfo =
		{"Weight: " + FString::SanitizeFloat(ItemBeingHovered->GetItemStackWeight())};

	
	MaxStackSizeText->SetText(FText::AsNumber(ItemBeingHovered->ItemStatistics.SellValue));
	StackWeight->SetText(FText::FromString(WeightInfo));

	

	if(ItemBeingHovered->NumericData.bIsStackable)
	{
		
		const FString StackInfo =
			{"MAX STACK SIZE: " + FString::FromInt(ItemBeingHovered->NumericData.MaxStackSize)};
		
		MaxStackSize->SetText(FText::AsNumber(ItemBeingHovered->NumericData.MaxStackSize));
	}
	else
	{
		MaxStackSize->SetVisibility(ESlateVisibility::Collapsed);
	}
	
}
