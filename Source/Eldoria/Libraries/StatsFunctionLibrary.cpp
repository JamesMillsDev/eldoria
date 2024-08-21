// Copyright James Mills - contact jcmills.developer@gmail.com


#include "StatsFunctionLibrary.h"

#include "Eldoria/Actors/Components/ActorComponents/CharacterSheetComponent.h"

int32 UStatsFunctionLibrary::CalculateHitPoints(UCharacterSheetComponent* CharacterSheet)
{
	int32 HitPoints = DiceTypeValue(CharacterSheet->GetHitDice());

	TArray<FCharacterAttribute> CapableAttributes;
	bool bFound = false;
	CharacterSheet->FindAttributesWithCapability(static_cast<int32>(EAttributeCapabilities::HitPoints), CapableAttributes, bFound);

	if (bFound)
	{
		for (const auto& Attribute : CapableAttributes)
		{
			HitPoints += CalculateModifier(Attribute.Value) * CharacterSheet->GetLevel();
		}
	}

	for(int32 I = 1; I < CharacterSheet->GetLevel(); ++I)
	{
		HitPoints += FMath::RandRange(1, DiceTypeValue(CharacterSheet->GetHitDice()));
	}

	return HitPoints;
}

int32 UStatsFunctionLibrary::DiceTypeValue(EDiceType Dice)
{
	return static_cast<int32>(Dice);
}

int32 UStatsFunctionLibrary::CalculateModifier(const int32 Value)
{
	return Value / 2 - 5;
}
