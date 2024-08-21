// Copyright James Mills - contact jcmills.developer@gmail.com


#include "CharacterSheetComponent.h"

#include "Eldoria/Libraries/StatsFunctionLibrary.h"

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
	MaxHitPoints = 0;
	CurrentHitPoints = 0;
}

FCharacterAttribute UCharacterSheetComponent::MakeAttribute(FName ID, bool bIsProficient, int32 Capabilities)
{
	FCharacterAttribute Attribute = FCharacterAttribute(ID);

	Attribute.AttributeCapabilities = Capabilities;
	Attribute.bIsProficient = bIsProficient;

	return Attribute;
}

int32 UCharacterSheetComponent::GetLevel() const
{
	return Level;
}

EDiceType UCharacterSheetComponent::GetHitDice() const
{
	return HitDice;
}

TArray<FCharacterAttribute> UCharacterSheetComponent::GetCharacterAttributes()
{
	return Attributes;
}

void UCharacterSheetComponent::AddAttribute(const FCharacterAttribute Attribute)
{
	Attributes.AddUnique(Attribute);
}

void UCharacterSheetComponent::FindAttribute(FName ID, FCharacterAttribute& Attribute, bool& bFound)
{
	for (auto& Attr : Attributes)
	{
		if (Attr.ID == ID)
		{
			bFound = true;
			Attribute = Attr;
			return;
		}
	}

	bFound = false;
}

void UCharacterSheetComponent::FindAttributesWithCapability(int32 Capability, TArray<FCharacterAttribute>& CapableAttributes,
	bool& bFound)
{
	bFound = false;

	for (auto& Attr : Attributes)
	{
		if ((Attr.AttributeCapabilities & Capability) == Capability)
		{
			bFound = true;
			CapableAttributes.Add(Attr);
		}
	}
}

void UCharacterSheetComponent::SetHitPoints()
{
	MaxHitPoints = UStatsFunctionLibrary::CalculateHitPoints(this);
	CurrentHitPoints = MaxHitPoints;
}

int32 UCharacterSheetComponent::GetMaxHitPoints() const
{
	return MaxHitPoints;
}

int32 UCharacterSheetComponent::GetCurrentHitPoints() const
{
	return CurrentHitPoints;
}
