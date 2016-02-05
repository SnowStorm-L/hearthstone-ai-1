#ifndef GAME_ENGINE_CARDS_CARD_CS2_189
#define GAME_ENGINE_CARDS_CARD_CS2_189

#include <stdexcept>
#include "game-engine/board.h"
#include "game-engine/card-id-map.h"
#include "game-engine/targetor.h"
#include "game-engine/stages/helper.h"

namespace GameEngine {
namespace Cards {

class Card_CS2_189
{
public:
	static constexpr int card_id = CARD_ID_CS2_189;

	// Elven Archer

	static void GetRequiredTargets(GameEngine::Board const& board, int playing_hero, TargetorBitmap &targets, bool & meet_requirements)
	{
		if (playing_hero == Targetor::GetPlayerHeroIndex()) {
			targets = Targetor::GetTargets(Targetor::TARGET_TYPE_OPPONENT_CHARACTERS_TARGETABLE_BY_ENEMY_SPELL, board);
		} 
		else if (playing_hero == Targetor::GetOpponentHeroIndex()) {
			targets = Targetor::GetTargets(Targetor::TARGET_TYPE_PLAYER_CHARACTERS_TARGETABLE_BY_ENEMY_SPELL, board);
		}
		else {
			throw std::runtime_error("consistency check failed");
		}

		meet_requirements = true; // it's fine even if no target available
	}

	static void BattleCry(GameEngine::Board & board, GameEngine::Move::PlayMinionData const& play_minion_data)
	{
		constexpr int damage = 1;

#ifdef DEBUG
		if (play_minion_data.target < 0) throw std::runtime_error("logic error");
#endif

		StageHelper::TakeDamage(board, play_minion_data.target, damage);
	}
};

} // namespace Cards
} // namespace GameEngine

#endif
