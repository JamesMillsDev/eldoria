// Copyright James Mills - contact jcmills.developer@gmail.com


#include "EldoriaPlayerCharacter.h"

#include "EldoriaPlayerController.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"

#include "Eldoria/Actors/Components/ActorComponents/PlayerCharacterSheetComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AEldoriaPlayerCharacter::AEldoriaPlayerCharacter()
{
	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	if(UCharacterMovementComponent* MovementComponent = GetCharacterMovement())
	{
		FMovementProperties& MovementProperties = MovementComponent->GetNavAgentPropertiesRef();

		MovementProperties.bCanCrouch = true;
	}

	CharacterSheet->DestroyComponent();

	CharacterSheet = CreateDefaultSubobject<UPlayerCharacterSheetComponent>(TEXT("PlayerCharacterSheet"));

	MakeDefaultAttributes();
}

void AEldoriaPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if(AEldoriaPlayerController* PlayerController = Cast<AEldoriaPlayerController>(Controller))
		{
			PlayerController->ConfigureInputComponent(EnhancedInput);
		}
	}
}