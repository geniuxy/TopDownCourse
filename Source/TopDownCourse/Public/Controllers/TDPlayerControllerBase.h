// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TDPlayerControllerBase.generated.h"

class UPaperFlipbook;
struct FInputActionValue;
class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class TOPDOWNCOURSE_API ATDPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=FlipBook)
	UPaperFlipbook* RightWalkFlipBook;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=FlipBook)
	UPaperFlipbook* LeftWalkFlipBook;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=FlipBook)
	UPaperFlipbook* DownWalkFlipBook;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=FlipBook)
	UPaperFlipbook* UpWalkFlipBook;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=FlipBook)
	UPaperFlipbook* RightIdleFlipBook;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=FlipBook)
	UPaperFlipbook* LeftIdleFlipBook;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=FlipBook)
	UPaperFlipbook* DownIdleFlipBook;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=FlipBook)
	UPaperFlipbook* UpIdleFlipBook;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(BlueprintReadOnly)
	FVector2D LastMoveVector = FVector2D(0.f, 1.f);
	
	virtual void HandleGroundMovementInput(const FInputActionValue& InputActionValue);
	virtual void HandleGroundMovementCompleted(const FInputActionValue& InputActionValue);
};
