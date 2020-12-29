// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "EnemyPathPoint.h"
#include "TDDemo/Enemy/BaseEnemy.h"
#include "Kismet/GameplayStatics.h"

//GetWorld需要引入Engine/World头文件
#include "Engine/World.h"


// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	
	Super::BeginPlay();

	
	

	SpawnEnemy();
	
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemySpawner::SpawnEnemy()
{
	if (Wave < EnemyArr.Num())
	{
		//创建敌人

		TSubclassOf<AActor> Enemy = EnemyArr[Wave++];
		AActor *EnemyActor = GetWorld()->SpawnActor<AActor>(Enemy, GetActorLocation(), GetActorRotation());
		
		ABaseEnemy *BaseEnemy = Cast<ABaseEnemy>(EnemyActor);
		if (BaseEnemy)
		{
			BaseEnemy->setTargetPoint(InitPoint);
		}
	}
	
}

