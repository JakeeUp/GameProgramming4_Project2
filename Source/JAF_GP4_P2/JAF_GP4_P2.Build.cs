// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class JAF_GP4_P2 : ModuleRules
{
	public JAF_GP4_P2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput","SlateCore","Slate","UMG" });
	}
}
