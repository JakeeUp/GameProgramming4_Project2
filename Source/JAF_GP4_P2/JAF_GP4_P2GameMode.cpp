// Copyright Epic Games, Inc. All Rights Reserved.

#include "JAF_GP4_P2GameMode.h"
#include "JAF_GP4_P2Character.h"
#include "UObject/ConstructorHelpers.h"

AJAF_GP4_P2GameMode::AJAF_GP4_P2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
