// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TDPaperCharacterBase.h"

#include "GameFramework/CharacterMovementComponent.h"

ATDPaperCharacterBase::ATDPaperCharacterBase()
{
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
}
