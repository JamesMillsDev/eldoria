// Copyright James Mills - contact jcmills.developer@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "Eldoria/Actors/Components/ActorComponents/CharacterSheetComponent.h"
#include "CharacterSheetSaveData.generated.h"

/**
 *
 */
USTRUCT()
struct FCharacterSheetSaveData
{
	GENERATED_BODY()

public:
	FCharacterSheetSaveData();

public:
	void Save(const UCharacterSheetComponent* CharacterSheet);
	void Load(UCharacterSheetComponent* CharacterSheet);

private:
	UPROPERTY()
	TArray<FCharacterAttribute> Attributes;

	UPROPERTY()
	int32 Level;

	UPROPERTY()
	EDiceType HitDice;

	UPROPERTY()
	int32 MaxHitPoints;

	UPROPERTY()
	int32 CurrentHitPoints;

};
