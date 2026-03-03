// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TDPaperZDEnemySkeleton.h"

#include "GameFramework/CharacterMovementComponent.h"

ATDPaperZDEnemySkeleton::ATDPaperZDEnemySkeleton()
{
	PrimaryActorTick.bCanEverTick = false;

	GetCharacterMovement()->MaxWalkSpeed = 100.f;
}
