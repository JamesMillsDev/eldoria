// Copyright James Mills - contact jcmills.developer@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "CharacterLevelTableRow.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct FCharacterLevelTableRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Eldoria", meta = (ClampMin = "0"))
	int32 RequiredExperience;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Eldoria", meta = (ClampMin = "2", ClampMax = "6", UIMin = "2", UIMax = "6"))
	int32 ProficiencyBonus;

public:
	FCharacterLevelTableRow();

};
