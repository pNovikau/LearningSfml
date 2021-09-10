#pragma once

namespace game
{
	class Constants
	{
	public:
		class Entities
		{
		public:
			inline static const std::string PLAYER_ID = "game_object_player";
			inline static const std::string BALL_ID = "game_object_ball";
		};

		class Tags
		{
		public:
			inline static const std::string WALL = "tag_wall";
            inline static const std::string TRIGGER = "tag_trigger";
		};
	};
}