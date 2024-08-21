// Copyright James Mills - contact jcmills.developer@gmail.com


#include "EldoriaPlayerController.h"

#include "EnhancedInputComponent.h"

#include "Eldoria/Actors/EldoriaCharacter.h"
#include "Eldoria/Data/EldoriaInputConfig.h"
#include "Eldoria/Data/EldoriaSaveGame.h"
#include "Eldoria/Framework/EldoriaGameInstance.h"

#include "GameFramework/Character.h"

#include "Kismet/GameplayStatics.h"

void AEldoriaPlayerController::ConfigureInputComponent(UEnhancedInputComponent* EnhancedInput)
{
	if(IsValid(EnhancedInput) && IsValid(InputConfig))
	{
		if(const UInputAction* Action = InputConfig->Find(EEldoriaInputID::Move))
		{
			EnhancedInput->BindAction(Action, ETriggerEvent::Triggered, this, &AEldoriaPlayerController::Move);
		}

		if (const UInputAction* Action = InputConfig->Find(EEldoriaInputID::Look))
		{
			EnhancedInput->BindAction(Action, ETriggerEvent::Triggered, this, &AEldoriaPlayerController::Look);
		}

		if(const UInputAction* Action = InputConfig->Find(EEldoriaInputID::Jump))
		{
			EnhancedInput->BindAction(Action, ETriggerEvent::Started, GetCharacter(), &ACharacter::Jump);
			EnhancedInput->BindAction(Action, ETriggerEvent::Completed, GetCharacter(), &ACharacter::StopJumping);
		}

		if (const UInputAction* Action = InputConfig->Find(EEldoriaInputID::Crouch))
		{
			EnhancedInput->BindAction(Action, ETriggerEvent::Started, GetCharacter(), &ACharacter::Crouch, false);
			EnhancedInput->BindAction(Action, ETriggerEvent::Completed, GetCharacter(), &ACharacter::UnCrouch, false);
		}
	}
}

void AEldoriaPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if(IsValid(InputConfig))
	{
		InputConfig->BindMappingContext(this);
	}
}

void AEldoriaPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if(UEldoriaGameInstance* GameInstance = Cast<UEldoriaGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		if (AEldoriaCharacter* EldoriaCharacter = Cast<AEldoriaCharacter>(InPawn))
		{
			if (GameInstance->bDidLoad)
			{
				GameInstance->Save->Load(EldoriaCharacter->GetCharacterSheet());
			}
			else
			{
				EldoriaCharacter->GetCharacterSheet()->SetHitPoints();
			}
		}
	}
}

void AEldoriaPlayerController::OnUnPossess()
{
	if (UEldoriaGameInstance* GameInstance = Cast<UEldoriaGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		if (AEldoriaCharacter* EldoriaCharacter = Cast<AEldoriaCharacter>(GetCharacter()))
		{
			GameInstance->Save->Save(EldoriaCharacter->GetCharacterSheet());
		}
	}

	Super::OnUnPossess();
}

// ReSharper disable CppMemberFunctionMayBeConst
void AEldoriaPlayerController::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (ACharacter* Char = GetCharacter())
	{
		// find out which way is forward
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		Char->AddMovementInput(ForwardDirection, MovementVector.Y);
		Char->AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AEldoriaPlayerController::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (ACharacter* Char = GetCharacter())
	{
		// add yaw and pitch input to controller
		Char->AddControllerYawInput(LookAxisVector.X);
		Char->AddControllerPitchInput(LookAxisVector.Y);
	}
}
// ReSharper restore CppMemberFunctionMayBeConst