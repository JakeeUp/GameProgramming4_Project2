// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterface/JAFTutorialHud.h"
#include "UserInterface/MainMenu.h"
#include "UserInterface/Interaction/InteractionWidget.h"

AJAFTutorialHud::AJAFTutorialHud()
{
}

void AJAFTutorialHud::BeginPlay()
{
	Super::BeginPlay();

	if(MainMenuClass)
	{
		MainMenuWidget = CreateWidget<UMainMenu>(GetWorld(), MainMenuClass);
		MainMenuWidget->AddToViewport(5);
		MainMenuWidget->SetVisibility(ESlateVisibility::Collapsed);
	}

	if(InteractionWidgetClass)
	{
		InteractionWidget = CreateWidget<UInteractionWidget>(GetWorld(), InteractionWidgetClass);
		InteractionWidget->AddToViewport(-1);
		InteractionWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void AJAFTutorialHud::DisplayMenu()
{
	if(MainMenuWidget)
	{
		bIsMenuVisible = true;
		MainMenuWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void AJAFTutorialHud::HideMenu()
{
	if(MainMenuWidget)
	{
		bIsMenuVisible = false;
		MainMenuWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void AJAFTutorialHud::ToggleMenu()
{
	if(bIsMenuVisible)
	{
		HideMenu();

		const FInputModeGameOnly InputMode;
		GetOwningPlayerController()->SetInputMode(InputMode);
		GetOwningPlayerController()->SetShowMouseCursor(false);
	}
	else if(!bIsMenuVisible)
	{
		DisplayMenu();
		const FInputModeGameAndUI InputMode;
		GetOwningPlayerController()->SetInputMode(InputMode);
		GetOwningPlayerController()->SetShowMouseCursor(true);
	}
}

void AJAFTutorialHud::ShowInteractionWidget()
{
	if(InteractionWidget)
	{
		InteractionWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void AJAFTutorialHud::HideInteractionWidget()
{
	if(InteractionWidget)
	{
		InteractionWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void AJAFTutorialHud::UpdateInteractionWidget(const FInteractableData* InteractableData)
{
	if(InteractionWidget)
	{
		if(InteractionWidget->GetVisibility() == ESlateVisibility::Collapsed)
		{
			InteractionWidget->SetVisibility(ESlateVisibility::Visible);
		}

		InteractionWidget->UpdateWidget(InteractableData);
	}
}

