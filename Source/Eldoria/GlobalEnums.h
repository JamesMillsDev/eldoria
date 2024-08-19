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