// Copyright James Mills - contact jcmills.developer@gmail.com


#include "EldoriaCharacter.h"

#include "Components/CapsuleComponent.h"
#include "Components/ActorComponents/CharacterSheetComponent.h"

#include "GameFramework/CharacterMovementComponent.h"

DEFINE_LOG_CATEGORY(LogEldoriaCharacter);

// Sets default values
AEldoriaCharacter::AEldoriaCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	if (UCapsuleComponent* Capsule = GetCapsuleComponent())
	{
		// Set size for collision capsule
		Capsule->InitCapsuleSize(42.f, 96.0f);
	}

	if (UCharacterMovementComponent* MovementComponent = GetCharacterMovement())
	{
		// Configure character movement
		MovementComponent->bOrientRotationToMovement = true; // Character moves in the direction of input...	
		MovementComponent->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

		// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
		// instead of recompiling to adjust them
		MovementComponent->JumpZVelocity = 420.f;
		MovementComponent->AirControl = 0.35f;
		MovementComponent->MaxWalkSpeed = 500.f;
		MovementComponent->MinAnalogWalkSpeed = 20.f;
		MovementComponent->BrakingDecelerationWalking = 2000.f;
		MovementComponent->BrakingDecelerationFalling = 1500.0f;
	}

	if(USkeletalMeshComponent* MeshComponent = GetMesh())
	{
		MeshComponent->SetRelativeLocationAndRotation(FVector(0, 0, -90.f), FRotator(0, -90.f, 0));
	}

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

	CharacterSheet = CreateDefaultSubobject<UCharacterSheetComponent>(TEXT("CharacterSheet"));

	CharacterSheet->AddAttribute(
		UCharacterSheetComponent::MakeAttribute(
			"Strength", false, static_cast<int32>(EAttributeCapabilities::SavingThrow)
		)
	);

	CharacterSheet->AddAttribute(
		UCharacterSheetComponent::MakeAttribute(
			"Dexterity", false, static_cast<int32>(EAttributeCapabilities::SavingThrow | EAttributeCapabilities::ArmourClass | EAttributeCapabilities::Initiative)
		)
	);

	CharacterSheet->AddAttribute(
		UCharacterSheetComponent::MakeAttribute(
			"Constitution", false, static_cast<int32>(EAttributeCapabilities::SavingThrow | EAttributeCapabilities::HitPoints)
		)
	);

	CharacterSheet->AddAttribute(
		UCharacterSheetComponent::MakeAttribute(
			"Intelligence", false, static_cast<int32>(EAttributeCapabilities::SavingThrow)
		)
	);

	CharacterSheet->AddAttribute(
		UCharacterSheetComponent::MakeAttribute(
			"Wisdom", false, static_cast<int32>(EAttributeCapabilities::SavingThrow)
		)
	);

	CharacterSheet->AddAttribute(
		UCharacterSheetComponent::MakeAttribute(
			"Charisma", false, static_cast<int32>(EAttributeCapabilities::SavingThrow)
		)
	);
}