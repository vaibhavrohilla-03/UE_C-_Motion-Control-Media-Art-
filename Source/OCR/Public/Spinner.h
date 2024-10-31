// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spinner.generated.h"

UCLASS()
class OCR_API ASpinner : public AActor
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Sets default values for this actor's properties
	ASpinner();

	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		TObjectPtr<UStaticMeshComponent> Base;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		TObjectPtr<UStaticMeshComponent> Arm_1;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		TObjectPtr<UStaticMeshComponent> Arm_2End;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		TObjectPtr<UStaticMeshComponent> Arm_2Light;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		TObjectPtr<UStaticMeshComponent> Arm_2Bar;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		TObjectPtr<UStaticMeshComponent> Arm_2Start;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		TObjectPtr<class UArrowComponent> arrow;
	

private:
	

	UPROPERTY(EditAnywhere)
		TObjectPtr<class UPhysicsConstraintComponent> PC_Base;

	UPROPERTY(EditAnywhere)
		TObjectPtr<UPhysicsConstraintComponent> PC_Joint;

	UPROPERTY(EditInstanceOnly)
		TObjectPtr<class AOSCactor> Osc;

	UPROPERTY(EditAnywhere)
		float ImpulseScaler = 0.5f;
	UFUNCTION(BlueprintCallable)
		void AddImpulse();

	FVector GetImpulseVector();
};
