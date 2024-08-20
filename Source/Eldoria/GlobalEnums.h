// Copyright James Mills - contact jcmills.developer@gmail.com

#pragma once

#include "CoreMinimal.h"

/**
 *
 */
UENUM(BlueprintType)
enum class EEldoriaInputID : uint8
{
	None,
	Confirm,
	Cancel,
	Move,
	Look,
	Jump,
	Crouch,
	Sprint
};

/**
 *
 */
UENUM(BlueprintType, Flags)
enum class EAttributeCapabilities : uint8
{
	None,
	SavingThrow = 1 << 1 UMETA(Tooltip = "Enabling this allows the attribute to be used for saving throws."),
	ArmourClass = 1 << 2 UMETA(DisplayName = "Affects Armour Class", Tooltip = "Enabling this allows the attribute to affect the AC calculations."),
	Initiative = 1 << 3 UMETA(DisplayName = "Affects Initiative", Tooltip = "Enabling this allows the attribute to affect the Initiative calculations."),
	HitPoints = 1 << 4 UMETA(DisplayName = "Affects Hit Points", Tooltip = "Enabling this allows the attribute to affect the Hit Point calculations.")
};
ENUM_CLASS_FLAGS(EAttributeCapabilities)

/**
 *
 */
UENUM(BlueprintType)
enum class EDiceType : uint8
{
	None UMETA(DisplayName = "Invalid"),
	D2 UMETA(DisplayName = "Coin Flip"),
	D4 UMETA(DisplayName = "d4"),
	D6 UMETA(DisplayName = "d6"),
	D8 UMETA(DisplayName = "d8"),
	D10 UMETA(DisplayName = "d10"),
	D12 UMETA(DisplayName = "d12"),
	D20 UMETA(DisplayName = "d20"),
	D100 UMETA(DisplayName = "d100")
};