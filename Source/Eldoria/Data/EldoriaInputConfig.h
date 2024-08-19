// Copyright James Mills - contact jcmills.developer@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "Eldoria/GlobalEnums.h"
#include "Engine/DataAsset.h"
#include "EldoriaInputConfig.generated.h"

/**
 *
 */
UCLASS()
class ELDORIA_API UEldoriaInputConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UEldoriaInputConfig();

public:
	UFUNCTION(BlueprintCallable, Category = "Eldoria|Input", meta = (DisplayName = "Find Input Action"))
	class UInputAction* Find(EEldoriaInputID InputID) const;

	UFUNCTION(BlueprintCallable, Category = "Eldoria|Input")
	void BindMappingContext(class APlayerController* PlayerController) const;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	TMap<EEldoriaInputID, class UInputAction*> Actions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	class UInputMappingContext* MappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	int32 MappingPriority;

};
