// Copyright James Mills - contact jcmills.developer@gmail.com

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EldoriaCharacter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogEldoriaCharacter, Log, All);

UCLASS(NotBlueprintable, Abstract)
class ELDORIA_API AEldoriaCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	FORCEINLINE class UCharacterSheetComponent* GetCharacterSheet() const { return CharacterSheet; }

public:
	// Sets default values for this character's properties
	AEldoriaCharacter();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	class UCharacterSheetComponent* CharacterSheet;

protected:
	UFUNCTION()
	void MakeDefaultAttributes();

private:
	UFUNCTION()
	void OnTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);


};
