// Copyright James Mills - contact jcmills.developer@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GlobalGameConfig.generated.h"

/**
 * 
 */
UCLASS()
class ELDORIA_API UGlobalGameConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UDataTable* LevelDataTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 MaxLevel;

public:
	UGlobalGameConfig();
	
};
