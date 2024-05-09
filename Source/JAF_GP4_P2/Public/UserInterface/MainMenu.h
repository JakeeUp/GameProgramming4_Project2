// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "JAF_GP4_P2/JAF_GP4_P2Character.h"
#include "MainMenu.generated.h"

class AJAF_GP4_P2Character;
/**
 * 
 */
UCLASS()
class JAF_GP4_P2_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()


public:
	UPROPERTY()
	AJAF_GP4_P2Character* PlayerCharacter;
protected:
	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
		UDragDropOperation* InOperation) override;
};
