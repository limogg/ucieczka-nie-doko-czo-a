


#include "DorsOpenComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDorsComponent::UOpenDorsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDorsComponent::BeginPlay()
{
	Super::BeginPlay();


	// FRotator OpenDor {0.f,100.f,0.f};
	
}



// Called every frame
void UOpenDorsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner() -> GetActorRotation().ToString());
	
	UE_LOG(LogTemp, Warning, TEXT("Yaw to :%f"), GetOwner() -> GetActorRotation().Yaw);
	float CurrentYaw = GetOwner() -> GetActorRotation().Yaw;
	FRotator OpenDor (0.f,TargetYawn ,0.f);
	OpenDor.Yaw = FMath::Lerp(CurrentYaw, TargetYawn, 0.2f);
	GetOwner() -> SetActorRotation(OpenDor);

}

