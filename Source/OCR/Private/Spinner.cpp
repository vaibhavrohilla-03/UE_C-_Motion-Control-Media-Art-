// Fill out your copyright notice in the Description page of Project Settings.

#include "Spinner.h"
#include "OSCactor.h"
#include "Components/ArrowComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

// Sets default values
ASpinner::ASpinner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));

	Base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base"));
	Base->SetupAttachment(RootComponent);

	Arm_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Arm1"));
	Arm_1->SetupAttachment(RootComponent);
	
	arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ImpulseArrow"));
	
	arrow->AttachToComponent(Arm_1,FAttachmentTransformRules::KeepRelativeTransform);

	Arm_2End = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Arm2End"));
	Arm_2End->SetupAttachment(RootComponent);

	Arm_2Light = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Arm2light"));
	Arm_2Bar = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Arm2bar"));
	Arm_2Start = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Arm2Start"));
	Arm_2Light->SetupAttachment(Arm_2End);
	Arm_2Bar->SetupAttachment(Arm_2End);
	Arm_2Start->SetupAttachment(Arm_2End);

	PC_Base = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("PCBase"));
	PC_Joint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("PCJoint"));

	PC_Base->SetupAttachment(RootComponent);
	PC_Joint->SetupAttachment(RootComponent);

	Arm_1->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void ASpinner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpinner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(Osc->updated)
	{
		AddImpulse();
	}
}

FVector ASpinner::GetImpulseVector()
{
	FVector forward =  arrow->GetForwardVector();
	FVector location = arrow->GetComponentLocation();
	float accelx = Osc->ValueX;

	FVector impulse = ((accelx*ImpulseScaler)*forward) + location;

	return impulse;
}

void ASpinner::AddImpulse()
{
	if (Osc != nullptr)
	{
		// Capture initial velocity
		FVector InitialVelocity = Arm_1->GetPhysicsLinearVelocity();

		// Apply impulse
		Arm_1->AddImpulseAtLocation(GetImpulseVector(),arrow->GetComponentLocation());

		// Capture final velocity
		FVector FinalVelocity = Arm_1->GetPhysicsLinearVelocity();

		// Check if the impulse was applied
		if (!FinalVelocity.Equals(InitialVelocity, KINDA_SMALL_NUMBER))
		{
			UE_LOG(LogTemp, Log, TEXT("Impulse applied successfully. Initial velocity: %s, Final velocity: %s"),
				   *InitialVelocity.ToString(), *FinalVelocity.ToString());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Impulse not applied, velocities are equal."));
		}
	}
}


