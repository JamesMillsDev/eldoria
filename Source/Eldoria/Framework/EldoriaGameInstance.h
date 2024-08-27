// Copyright James Mills - contact jcmills.developer@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "EldoriaGameInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSaveLoad, class UEldoriaSaveGame*&, Save, bool, bIsSaving);

/**
 * 
 */
UCLASS()
class ELDORIA_API UEldoriaGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY()
	class UEldoriaSaveGame* Save;

	UPROPERTY()
	bool bDidLoad;

	UPROPERTY(BlueprintAssignable)
	FOnSaveLoad OnSaveLoad;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UGlobalGameConfig* GlobalConfig;

public:
	UEldoriaGameInstance();

public:
	virtual void Init() override;
	virtual void Shutdown() override;
	
};
