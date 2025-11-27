#include "MyRPGAttributeSet.h"
#include "Net/UnrealNetwork.h"

UMyRPGAttributeSet::UMyRPGAttributeSet()
{
	// Valor inicial (opcional)
	InitCharge(500.0f);
}

void UMyRPGAttributeSet::OnRep_Charge(const FGameplayAttributeData& OldCharge)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyRPGAttributeSet, Charge, OldCharge);
}

void UMyRPGAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Registra o atributo para replicação
	DOREPLIFETIME_CONDITION_NOTIFY(UMyRPGAttributeSet, Charge, COND_None, REPNOTIFY_Always);
}
