// Copyright James Mills - contact jcmills.developer@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "CharacterSheetComponent.h"

#include "PlayerCharacterSheetComponent.generated.h"

/**
 *
 */
UCLASS()
class ELDORIA_API UPlayerCharacterSheetComponent : public UCharacterSheetComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	int32 CurrentExperience;

private:
	UFUNCTION()
	void OnSaveLoad(class UEldoriaSaveGame*& Save, bool bIsSaving);

};
