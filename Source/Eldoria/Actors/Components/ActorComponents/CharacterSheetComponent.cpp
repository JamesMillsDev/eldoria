// Copyright James Mills - contact jcmills.developer@gmail.com


#include "CharacterSheetComponent.h"

FCharacterAttribute::FCharacterAttribute()
{
	ID = "None";
	bIsProficient = false;
	Value = 10;
	ModifierID = "None";

	AttributeCapabilities = 0;
}

FCharacterAttribute::FCharacterAttribute(const FName Name)
{
	ID = Name;
	bIsProficient = false;
	Value = 10;
	ModifierID = "None";

	AttributeCapabilities = 0;
}

bool FCharacterAttribute::operator==(const FCharacterAttribute& RHS) const
{
	return ID == RHS.ID;
}

bool FCharacterAttribute::operator!=(const FCharacterAttribute& RHS) const
{
	return ID != RHS.ID;
}

// Sets default values for this component's properties
UCharacterSheetComponent::UCharacterSheetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	Level = 1;
	HitDice = EDiceType::D8;
}

FCharacterAttribute UCharacterSheetComponent::MakeAttribute(FName ID, bool bIsProficient, int32 Capabilities)
{
	FCharacterAttribute Attribute = FCharacterAttribute(ID);

	Attribute.AttributeCapabilities = Capabilities | static_cast<int32>(EAttributeCapabilities::None);
	Attribute.bIsProficient = bIsProficient;

	return Attribute;
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

void UCharacterSheetComponent::AddAttribute(const FCharacterAttribute Attribute)
{
	Attributes.AddUnique(Attribute);
}
