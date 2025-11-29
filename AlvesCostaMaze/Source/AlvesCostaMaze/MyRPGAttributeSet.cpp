#include "MyRPGAttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameplayEffectExtension.h"
UMyRPGAttributeSet::UMyRPGAttributeSet()
{
	// Valor inicial (opcional)
	InitCharge(500.0f);
	InitSpeed(10);
}

void UMyRPGAttributeSet::OnRep_Charge(const FGameplayAttributeData& OldCharge)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyRPGAttributeSet, Charge, OldCharge);
}
void UMyRPGAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyRPGAttributeSet, Speed, OldSpeed);
}

void UMyRPGAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Registra o atributo para replicação
	DOREPLIFETIME_CONDITION_NOTIFY(UMyRPGAttributeSet, Charge, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyRPGAttributeSet, Speed, COND_None, REPNOTIFY_Always);
}
void UMyRPGAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	// Não vamos colocar código aqui.
	// O atributo Speed vai mudar, e você lê ele no Blueprint quando precisar.
}