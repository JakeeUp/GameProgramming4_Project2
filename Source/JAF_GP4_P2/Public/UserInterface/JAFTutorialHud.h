// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainMenu.h"
#include "GameFramework/HUD.h"
#include "Interaction/InteractionWidget.h"
#include "JAF_GP4_P2/JAF_GP4_P2Character.h"
#include "JAFTutorialHud.generated.h"

class UInteractionWidget;
class UMainMenu;


/**
 * 
 */
UCLASS()
class JAF_GP4_P2_API AJAFTutorialHud : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UMainMenu> MainMenuClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UInteractionWidget> InteractionWidgetClass;

	bool bIsMenuVisible;

	//FUNCTIONS

	AJAFTutorialHud();

	void DisplayMenu();
	void HideMenu();

	void ShowInteractionWidget();
	void HideInteractionWidget();
	void UpdateInteractionWidget (const FInteractionData* InteractableData);

protected:

	UPROPERTY()
	UMainMenu* MainMenuWidget;

	UPROPERTY()
	UInteractionWidget* InteractionWidget;

	virtual void BeginPlay() override;
};
