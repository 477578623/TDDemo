// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class TDDEMO_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<AActor>> EnemyArr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Point")
	class AEnemyPathPoint *InitPoint;

	FTimerHandle SpawnEnemyTimerHandle;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnEnemy();


private:

	// todo ∂¡≈‰÷√±Ì
	int Wave = 0;
	int cnt = 10;
};
