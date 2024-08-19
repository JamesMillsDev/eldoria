// Copyright James Mills - contact jcmills.developer@gmail.com


#include "CharacterSheetComponent.h"

// Sets default values for this component's properties
UCharacterSheetComponent::UCharacterSheetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	Level = 1;
}

void UCharacterSheetComponent::FindAttribute(FName ID, FCharacterAttribute& Attribute, bool& bFound)
{
	for(auto& Attr : Attributes)
	{
		if(Attr.ID == ID)
		{
			bFound = true;
			Attribute = Attr;
			return;
		}
	}

	bFound = false;
}

int32 UCharacterSheetComponent::GetLevel() const
{
	return Level;
}
