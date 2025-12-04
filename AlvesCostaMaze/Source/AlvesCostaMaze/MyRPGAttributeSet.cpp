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

	InitHealth(100.0f);
	InitMaxHealth(100.0f);
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
	DOREPLIFETIME_CONDITION_NOTIFY(UMyRPGAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyRPGAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
}
void UMyRPGAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	// Não vamos colocar código aqui.
	// O atributo Speed vai mudar, e você lê ele no Blueprint quando precisar.
}
void UMyRPGAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyRPGAttributeSet, Health, OldHealth);
}

void UMyRPGAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyRPGAttributeSet, MaxHealth, OldMaxHealth);
}

// Essa função impede que a vida fique negativa ou maior que o máximo
void UMyRPGAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	// Se o atributo que está mudando for a VIDA
	if (Attribute == GetHealthAttribute())
	{
		// Pega o valor da Vida Máxima
		float MaxHp = GetMaxHealth();

		// Trava o valor entre 0 e MaxHp
		// Ex: Se curar para 150, ele trava em 100. Se dano levar a -20, trava em 0.
		NewValue = FMath::Clamp(NewValue, 0.0f, MaxHp);
	}
}