// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TDPaperZDEnemyBoar.h"

#include "GameFramework/CharacterMovementComponent.h"

ATDPaperZDEnemyBoar::ATDPaperZDEnemyBoar()
{
	PrimaryActorTick.bCanEverTick = false;

	GetCharacterMovement()->MaxWalkSpeed = 120.f;
}
