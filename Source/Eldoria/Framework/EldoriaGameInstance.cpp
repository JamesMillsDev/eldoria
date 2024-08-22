// Copyright James Mills - contact jcmills.developer@gmail.com


#include "EldoriaGameInstance.h"

#include "Eldoria/Data/EldoriaSaveGame.h"

#include "GameFramework/SaveGame.h"

#include "Kismet/GameplayStatics.h"

UEldoriaGameInstance::UEldoriaGameInstance()
{
	MaxLevel = 20;
}

void UEldoriaGameInstance::Init()
{
	Super::Init();

	const bool bCanLoad = UGameplayStatics::DoesSaveGameExist(TEXT("Singleplayer"), 0);
	USaveGame* Loaded;

	if (bCanLoad)
	{
		Loaded = UGameplayStatics::LoadGameFromSlot(TEXT("Singleplayer"), 0);
		bDidLoad = true;
	}
	else
	{
		Loaded = UGameplayStatics::CreateSaveGameObject(UEldoriaSaveGame::StaticClass());
		bDidLoad = false;
	}

	Save = Cast<UEldoriaSaveGame>(Loaded);
}

void UEldoriaGameInstance::Shutdown()
{
	UGameplayStatics::SaveGameToSlot(Save, TEXT("Singleplayer"), 0);

	Super::Shutdown();
}