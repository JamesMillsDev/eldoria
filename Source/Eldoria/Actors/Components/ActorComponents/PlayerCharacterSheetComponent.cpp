// Copyright James Mills - contact jcmills.developer@gmail.com


#include "PlayerCharacterSheetComponent.h"

#include "Eldoria/Data/EldoriaSaveGame.h"
#include "Eldoria/Framework/EldoriaGameInstance.h"

#include "Kismet/GameplayStatics.h"

void UPlayerCharacterSheetComponent::BeginPlay()
{
	Super::BeginPlay();

	if(UEldoriaGameInstance* GameInstance = Cast<UEldoriaGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		GameInstance->OnSaveLoad.AddUniqueDynamic(this, &UPlayerCharacterSheetComponent::OnSaveLoad);
	}
}

void UPlayerCharacterSheetComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (UEldoriaGameInstance* GameInstance = Cast<UEldoriaGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		GameInstance->OnSaveLoad.RemoveDynamic(this, &UPlayerCharacterSheetComponent::OnSaveLoad);
	}
}

void UPlayerCharacterSheetComponent::OnSaveLoad(UEldoriaSaveGame*& Save, bool bIsSaving)
{
	if(bIsSaving)
	{
		Save->PlayerCharacterExperience = CurrentExperience;
	}
	else
	{
		CurrentExperience = Save->PlayerCharacterExperience;
	}
}
