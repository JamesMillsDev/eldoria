// Copyright James Mills - contact jcmills.developer@gmail.com


#include "EldoriaInputConfig.h"

#include "EnhancedInputSubsystems.h"

UEldoriaInputConfig::UEldoriaInputConfig()
{
	MappingContext = nullptr;
	MappingPriority = 0;
}

UInputAction* UEldoriaInputConfig::Find(const EEldoriaInputID InputID) const
{
	if(Actions.Contains(InputID))
	{
		return Actions.FindRef(InputID);
	}

	return nullptr;
}

void UEldoriaInputConfig::BindMappingContext(APlayerController* PlayerController) const
{
	if(UEnhancedInputLocalPlayerSubsystem* Subsystem = PlayerController->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
	{
		Subsystem->AddMappingContext(MappingContext, MappingPriority);
	}
}
