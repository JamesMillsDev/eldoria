// Copyright James Mills - contact jcmills.developer@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "Eldoria/GlobalEnums.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StatsFunctionLibrary.generated.h"

/**
 *
 */
UCLASS()
class ELDORIA_API UStatsFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static int32 CalculateHitPoints(class UCharacterSheetComponent* CharacterSheet);

	UFUNCTION(BlueprintPure)
	static int32 DiceTypeValue(EDiceType Dice);

	UFUNCTION(BlueprintPure)
	static int32 CalculateModifier(int32 Value);

};
