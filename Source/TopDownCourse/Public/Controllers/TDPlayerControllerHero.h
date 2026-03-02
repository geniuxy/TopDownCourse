// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TDPlayerControllerBase.h"
#include "TDPlayerControllerHero.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNCOURSE_API ATDPlayerControllerHero : public ATDPlayerControllerBase
{
	GENERATED_BODY()

protected:
	virtual void HandleGroundMovementInput(const FInputActionValue& InputActionValue) override;

	virtual void HandleGroundMovementCompleted(const FInputActionValue& InputActionValue) override;
};
