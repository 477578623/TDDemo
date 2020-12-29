// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPathPoint.h"
#include "GameFramework/Actor.h"

// Sets default values
AEnemyPathPoint::AEnemyPathPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyPathPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyPathPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

