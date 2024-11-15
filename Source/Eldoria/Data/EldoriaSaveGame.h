// Copyright James Mills - contact jcmills.developer@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "CharacterSheetSaveData.h"
#include "GameFramework/SaveGame.h"
#include "EldoriaSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class ELDORIA_API UEldoriaSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FCharacterSheetSaveData CharacterSave;

	UPROPERTY()
	int32 PlayerCharacterExperience;

public:
	void Save(class UCharacterSheetComponent* Character);
	void Load(class UCharacterSheetComponent* Character);
	
};
