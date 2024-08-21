// Copyright James Mills - contact jcmills.developer@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "EldoriaGameInstance.generated.h"

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

public:
	virtual void Init() override;
	virtual void Shutdown() override;
	
};
