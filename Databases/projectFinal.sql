CREATE TABLE PLAYER (
        PLAYER_ID INT PRIMARY KEY,
        PLAYER_USERNAME VARCHAR(50),
    ORG_ID INT
);
CREATE TABLE TEAM_ASSIGN (
  ASSIGN_ID  INT PRIMARY KEY,
  GAME_ID INT,
  PLAYER_ID INT,
  TEAM_ID INT
);
CREATE TABLE TEAMS (#Done
  TEAM_ID INT PRIMARY KEY,
  TEAM_SIDE VARCHAR(5)
);
CREATE TABLE GAME (
  GAME_ID INT PRIMARY KEY,
  VICTOR_TEAM_ID INT,
  GAMEMODE VARCHAR(20)
);
CREATE TABLE PER_GAME_PERFORMANCE (
  PERFORMANCE_ID INT PRIMARY KEY,
  GAME_ID INT,
  PLAYER_ID INT,
  PLAYER_KILLS INT,
  PLAYER_DEATHS INT,
  PLAYER_ASSISTS INT,
  PLAYER_GOLD INT,
  PLAYER_LEVEL INT,
  PLAYER_ROLE VARCHAR(10),
  CHAMP_ID INT,
  RUNE_ID INT,
  PLAYERBUILD_ID INT
);




CREATE TABLE CHAMPIONS (#Done
  CHAMP_ID  INT PRIMARY KEY,
  CHAMP_NAME VARCHAR(20),
  CHAMP_ROLE VARCHAR(20)
);
CREATE TABLE PLAYER_ITEMS (
  PLAYERBUILD_ID INT PRIMARY KEY,
  PERFORMANCE_ID INT, 
  ITEM_1_ID INT,
  ITEM_2_ID INT,
  ITEM_3_ID INT,
  ITEM_4_ID INT,
  ITEM_5_ID INT,
  ITEM_6_ID INT
);
CREATE TABLE ITEMS (#Done
  ITEM_ID  INT PRIMARY KEY,
  ITEM_NAME VARCHAR(40)
);
CREATE TABLE RUNES (#Done
  RUNE_ID  INT PRIMARY KEY,
  RUNE_NAME VARCHAR(20),
  RUNE_TREE VARCHAR(20)
);
CREATE TABLE ORGANIZATIONS (#Done
  ORG_ID INT PRIMARY KEY,
  ORG_NAME VARCHAR(20),
  ORG_REGION VARCHAR(20)
);
CREATE TABLE PRO_PLAYERS (
  PRO_ID INT PRIMARY KEY,
  ORG_ID INT,
  PLAYER_ID INT,
  POSITION VARCHAR(10)
);
CREATE TABLE STREAMERS (#DONE
  STREAMER_ID INT PRIMARY KEY,
  STREAMER_NAME VARCHAR(20),
  ORG_ID INT,
  PLAYER_ID INT,
  PLATFORM VARCHAR(10)
);
CREATE TABLE TOURNAMENTS (#Done
  TOURNAMENT_ID INT PRIMARY KEY,
  TOURNAMENT_NAME VARCHAR(20),
  PRIZE_MONEY INT,
  ORG_WINNER_ID INT,
  ORG_RUNNER_UP INT
);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (1, 1, 142, 37, NULL, 179, 124, 73); 
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (2, 2, 173, 168, 110, 34, 103, 151);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (3, 3, 177, 30, 117, 129, 136, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (4, 4, 193, 151, 33, 72, 137, 61);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (5, 5, 190, 153, 146, 33, 165, 132 );
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (6, 6, 171, 152, 37, 135, 88, 54);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (7, 7, 159, 144, 30, 107, 182, 136);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (8, 8, 120, 149, 142, 183, 115, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (9, 9, 182, 136, 6, 147, 141, 108);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (10, 10, 140, 175, 36, 120, 60, 80);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (11, 11, 57, 191, 51, 36, 6, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (12, 12, 175, NULL, 112, 73, 21, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (13, 13, 33, 137, 151, 173, 150, 18);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (14, 14, 180, 141, 129, 30, 126, 64);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (15, 15, 153, 185, 35, 138, 45, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (16, 16, 145, 178, 114, 64, 95, 36);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (17, 17, 36, 178, 157, 122, 114, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (18, 18, 170, 37, 40, 112, 164, 56);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (19, 19, 147, 182, 30, 77, 42, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (20, 20, 153, 111, 47, 47, 38, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (21, 21, 133, 125, 193, 19, 83, 51);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (22, 22, 36, 168, 61, 103, 75, 73);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (23, 23, 73, 33, 164, 185, 149, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (24, 24, 109, 174, 169, 36, 60, 51);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (25, 25, 36, 122, 182, 144, 141, 150);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (26, 26, 3, 144, 177, 129, 32, 49);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (27, 27, 153, 58, 183, 37, 40, NULL );
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (28, 28, 183, 101, 115, 135, NULL, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (29, 29, 9, 180, 107, 36, 114, NULL );
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (30, 30, 82, 65, 54, 33, 183, 115);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (31, 31, 182, 30, 147, 108, 77, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (32, 32, 185, 37, 124, 142, NULL, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (33, 33, 192, 34, 160, 80, 97, 51);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (34, 34, 183, 54, 115, 142, 37, 59);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (35, 35, 181, 137, 33, 103, 65, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (36, 36, 173, 151, 103, 33, 23, 89);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (37, 37, 118, 171, 159, 34, 157, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (38, 38, 3, 157, 171, 36, 61, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (39, 39, 54, 23, 183, 115, 33, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (40, 40, 187, 37, 2, 152, 38, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (41, 41, 180, 159, 36, 39, 3, 42);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (42, 42, 111, 153, 186, 18, 35, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (43, 43, 34, 178, 61, 49, 3, 3);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (44, 44, 23, 187, 37, 152, NULL, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (45, 45, 5, 30, 180, 46, 44, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (46, 46, 180, 92, 85, 30, NULL, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (47, 47, 55, 91, 18, 75, 34, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (48, 48, 57, 36, 60, 100, 48, 43);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (49, 49, 176, 68, 33, 60, 2, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (50, 50, 157, 178, 5, 36, NULL, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (51, 51, 4, 183, 65, 2, 73, 37);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (52, 52, 75, 23, 33, 153, 48, 54);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (53, 53, 3, 161, 34, 64, 61, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (54, 54, 107, 23, 171, 46, 18, 36);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (55, 55, 40, 175, 4, 33, 112, 82);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (56, 56, 3, 180, 129, 30, 42, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (57, 57, 33, 140, 174, 63, 75, 18);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (58, 58, 178, 33, 46, 110, 61, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (59, 59, 179, 23, 128, 37, 38, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (60, 60, 23, 188, 77, 150, 64, 34);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (61, 61, 180, 49, 30, 89, 129, 42);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (62, 62, 33, 75, 82, 153, 18, 54);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (63, 63, 157, 178, 151, 18, 36, 3);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (64, 64, 114, 171, 157, 46, 36, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (65, 65, 179, 41, 138, 37, 43, 132);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (66, 66, 3, 180, 126, 129, 30, 42);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (67, 67, 140, 184, 127, 33, 51, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (68, 68, 180, 23, 61, 117, 77, 36);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (69, 69, 160, 192, 33, 51, 95, 2);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (70, 70, 132, 54, 179, 142, 38, 37);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (71, 71, 144, 177, 36, 76, NULL, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (72, 72, 18, 140, 184, 23, 36, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (73, 73, 173, 23, 137, 46, 46, 31);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (74, 74, 36, 23, 168, 81, NULL, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (75, 75, 2, 175, 144, 33, 94, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (76, 76, 30, 177, 49, 144, 39, 42);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (77, 77, 168, 36, 23, 81, NULL, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (78, 78, 2, 175, 33, 144, 94, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (79, 79, 30, 177, 144 , 49, 39, 42);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (80, 80, 109, 174, 52, 35, NULL, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (81, 81, 99, 75, 34, 194, 60, 51);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (82, 82, 37, 132, 179, 152, 142, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (83, 83, 3, 136, 180, 206, 39, 30);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (84, 84, 177, 126, 144, 129, 159, 32);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (85, 85, 34, 174, 109, 100, 51, 18);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (86, 86, 178, 105, 18, 83, 49, 36);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (87, 87, 171, 143, 157, 90, 51, 36 );
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (88, 88, 175, 37, 164, 104, 142, 100);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (89, 89, 137, 117, 92, 33, 170, 151);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (90, 90, 33, 184, 109, 100, NULL, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (91, 91, 57, 23, 60, 36, 18, 5);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (92, 92, 178, 36, 23, 51, NULL, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (93, 93, 31, 170, 2, 19, NULL, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (94, 94, 3, 93, 36, 81, 42, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (95, 95, 91, 75, 43, 18, 48, 33);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (96, 96, 5, 23, 171, 18, NULL, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (97, 97, 178, 36, 23, 64, NULL, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (98, 98, 185, 18, 19, 37, 82, NULL);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (99, 99, 18, 37, 4, 17, 170, 40);
insert into PLAYER_ITEMS (PLAYERBUILD_ID, PERFORMANCE_ID, ITEM_1_ID, ITEM_2_ID, ITEM_3_ID, ITEM_4_ID, ITEM_5_ID, ITEM_6_ID) values (100, 100, 33, 91, 190, NULL, NULL, NULL);




#Player Table Insertion
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (1, 'Other Account is', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (2, 'Fake Bus', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (3, 'SehwayJesus23', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (4, 'Bronzie ADC', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (5, 'JungleJim89', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (6, 'groza', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (7, 'puffydaaddy', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (8, 'DrywallEnjoyer', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (9, 'DarknessAbsol359', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (10, 'Zorok', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (11, 'SmashininChild', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (12, 'Esses', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (13, 'TheFranchyse', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (14, 'PowerlineNA', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (15, 'DrBeee', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (16, 'Mrstart0ver', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (17, 'Hide in eyes', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (18, 'AllDogsAllMuted', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (19, 'Turtleaim', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (20, 'lululululufei', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (21, 'Spraxor II', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (22, 'LCR KODA', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (23, 'Hemigcentr', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (24, 'Zak47', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (25, 'Minjae', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (26, 'WafflesFTW', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (27, 'FrosstCake', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (28, 'Uggrn', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (29, 'Dr Bubu', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (30, 'YCJH', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (31, 'BaBeeBu', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (32, 'XIX XX I XIV', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (33, 'Elannil', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (34, 'MaKKabbaka', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (35, 'Theosyndachaisa', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (36, 'ClueDaddy', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (37, 'Alyrezec', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (38, 'SkiTzee', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (39, 'RiceLegend', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (40, 'Setoo Kaiba', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (41, 'Petals for Armor', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (42, 'UNCORRECT GG', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (43, 'OO9527', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (44, '0 n a t', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (45, 'TwitchTV Stevens', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (46, 'MAMMOTHMAN65', 6);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (47, 'Ineza', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (48, 'Its all about us', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (49, 'Mercenary X', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (50, 'Alien Hominid', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (51, 'Ttv Doglightning', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (52, 'Shernf1', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (53, 'eXyu', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (54, 'Melke', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (55, 'Lil tkay sb', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (56, 'Timeless', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (57, 'MengMengBaBe', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (58, 'Kelpo', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (59, 'twtvDoglightning', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (60, 'Inexhaustive', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (61, 'dominoeffect1', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (62, 'All Legends Die', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (63, 'Doublelift', 7);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (64, 'Loopk', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (65, 'Jjkinggg', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (66, 'twitter undebal1', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (67, 'KatEvolved', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (68, 'Asyc', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (69, 'Smooth1e', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (70, 'Dragoon', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (71, 'Vegeta', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (72, 'Shrimp Cpt', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (73, 'Latence', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (74, 'Shen1v9King', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (75, 'Roulette', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (76, 'Sertuss', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (77, 'DPMGODX1', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (78, 'Monsieur Oui', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (79, 'NattyNatt', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (80, 'Sofm Jr', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (81, 'G2 Leakos', 8);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (82, 'DizL1', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (83, 'NA Villain', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (84, 'Arhys', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (85, 'Carbono', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (86, 'Po Gap', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (87, 'Eneino', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (88, 'Aglaro', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (89, 'TOP LFT', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (90, 'Kral Strike', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (91, 'McNisqy', 12);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (92, 'Twtvsyndroomboy', NULL);
insert into PLAYER (PLAYER_ID, PLAYER_USERNAME, ORG_ID) values (93, 'ReX KoKo', NULL);
#Game Table Insertion
insert into GAME (GAME_ID, VICTOR_TEAM_ID, GAMEMODE) values (1, 2, 'Ranked Solo');
insert into GAME (GAME_ID, VICTOR_TEAM_ID, GAMEMODE) values (2, 1, 'Ranked Solo');
insert into GAME (GAME_ID, VICTOR_TEAM_ID, GAMEMODE) values (3, 1, 'Ranked Solo');
insert into GAME (GAME_ID, VICTOR_TEAM_ID, GAMEMODE) values (4, 1, 'ARAM');
insert into GAME (GAME_ID, VICTOR_TEAM_ID, GAMEMODE) values (5, 2, 'Ranked Solo');
insert into GAME (GAME_ID, VICTOR_TEAM_ID, GAMEMODE) values (6, 2, 'Ranked Solo');
insert into GAME (GAME_ID, VICTOR_TEAM_ID, GAMEMODE) values (7, 1, 'Ranked Solo');
insert into GAME (GAME_ID, VICTOR_TEAM_ID, GAMEMODE) values (8, 2, 'Ranked Solo');
insert into GAME (GAME_ID, VICTOR_TEAM_ID, GAMEMODE) values (9, 1, 'Ranked Solo');
insert into GAME (GAME_ID, VICTOR_TEAM_ID, GAMEMODE) values (10, 2, 'Ranked Solo');


#Streamers Table Insert
insert into STREAMERS (STREAMER_ID, STREAMER_NAME, ORG_ID, PLAYER_ID, PLATFORM) values (1, 'Sneaky', 2, NULL, 'Twitch');
insert into STREAMERS (STREAMER_ID, STREAMER_NAME, ORG_ID, PLAYER_ID, PLATFORM) values (2, 'Doublelift', 7, 64, 'Twitch');
insert into STREAMERS (STREAMER_ID, STREAMER_NAME, ORG_ID, PLAYER_ID, PLATFORM) values (3, 'Tyler1', 6, 46, 'Twitch');
insert into STREAMERS (STREAMER_ID, STREAMER_NAME, ORG_ID, PLAYER_ID, PLATFORM) values (4, 'Trick2G', NULL, 32, 'Youtube');
insert into STREAMERS (STREAMER_ID, STREAMER_NAME, ORG_ID, PLAYER_ID, PLATFORM) values (5, 'SirhcEz', NULL, NULL, 'Youtube');
#Tournaments Table Insert
insert into TOURNAMENTS (TOURNAMENT_ID, TOURNAMENT_NAME, PRIZE_MONEY, ORG_WINNER_ID, ORG_RUNNER_UP) values (1, 'Worlds 2021', 2225000, 5, 3);
insert into TOURNAMENTS (TOURNAMENT_ID, TOURNAMENT_NAME, PRIZE_MONEY, ORG_WINNER_ID, ORG_RUNNER_UP) values (2, 'Worlds 2020', 2225000, 3, 10);
insert into TOURNAMENTS (TOURNAMENT_ID, TOURNAMENT_NAME, PRIZE_MONEY, ORG_WINNER_ID, ORG_RUNNER_UP) values (3, 'Worlds 2019', 2225000, 4, 8);
insert into TOURNAMENTS (TOURNAMENT_ID, TOURNAMENT_NAME, PRIZE_MONEY, ORG_WINNER_ID, ORG_RUNNER_UP) values (4, 'Worlds 2018', 6450000, 11, 12);
insert into TOURNAMENTS (TOURNAMENT_ID, TOURNAMENT_NAME, PRIZE_MONEY, ORG_WINNER_ID, ORG_RUNNER_UP) values (5, 'Worlds 2017', 4946970, 13, 6);
#Organizations Table Insert
insert into ORGANIZATIONS (ORG_ID, ORG_NAME, ORG_REGION) values (1, 'Team Liquid', 'North America');
insert into ORGANIZATIONS (ORG_ID, ORG_NAME, ORG_REGION) values (2, 'Cloud9', 'North America');
insert into ORGANIZATIONS (ORG_ID, ORG_NAME, ORG_REGION) values (3, 'Damwon', 'Korea');
insert into ORGANIZATIONS (ORG_ID, ORG_NAME, ORG_REGION) values (4, 'FunPlus Phoenix', 'China');
insert into ORGANIZATIONS (ORG_ID, ORG_NAME, ORG_REGION) values (5, 'EDward Gaming', 'China');
insert into ORGANIZATIONS (ORG_ID, ORG_NAME, ORG_REGION) values (6, 'T1', 'Korea');
insert into ORGANIZATIONS (ORG_ID, ORG_NAME, ORG_REGION) values (7, 'TSM', 'North America');
insert into ORGANIZATIONS (ORG_ID, ORG_NAME, ORG_REGION) values (8, 'G2 Esports', 'Europe');
insert into ORGANIZATIONS (ORG_ID, ORG_NAME, ORG_REGION) values (9, 'Goldenrod', 'Blue');
insert into ORGANIZATIONS (ORG_ID, ORG_NAME, ORG_REGION) values (10, 'Weibo Gaming', 'China');
insert into ORGANIZATIONS (ORG_ID, ORG_NAME, ORG_REGION) values (11, 'Invictus Gaming', 'China');
insert into ORGANIZATIONS (ORG_ID, ORG_NAME, ORG_REGION) values (12, 'Fnatic', 'Europe');
insert into ORGANIZATIONS (ORG_ID, ORG_NAME, ORG_REGION) values (13, 'GenG', 'Korea');


#Teams Table Insertion
insert into TEAMS (TEAM_ID, TEAM_SIDE) values (1, 'Red');
insert into TEAMS (TEAM_ID, TEAM_SIDE) values (2, 'Blue');


#Rune Table Insertion
insert into RUNES (RUNE_ID, RUNE_NAME, RUNE_TREE) values (1, 'Press the Attack', 'Precision');
insert into RUNES (RUNE_ID, RUNE_NAME, RUNE_TREE) values (2, 'Lethal Tempo', 'Precision');
insert into RUNES (RUNE_ID, RUNE_NAME, RUNE_TREE) values (3, 'Fleet Footwork', 'Precision');
insert into RUNES (RUNE_ID, RUNE_NAME, RUNE_TREE) values (4, 'Conqueror', 'Precision');
insert into RUNES (RUNE_ID, RUNE_NAME, RUNE_TREE) values (5, 'Electrocute', 'Domination');
insert into RUNES (RUNE_ID, RUNE_NAME, RUNE_TREE) values (6, 'Predator', 'Domination');
insert into RUNES (RUNE_ID, RUNE_NAME, RUNE_TREE) values (7, 'Dark Harvest', 'Domination');
insert into RUNES (RUNE_ID, RUNE_NAME, RUNE_TREE) values (8, 'Hail of Blades', 'Domination');
insert into RUNES (RUNE_ID, RUNE_NAME, RUNE_TREE) values (9, 'Summon Aery', 'Sorcery');
insert into RUNES (RUNE_ID, RUNE_NAME, RUNE_TREE) values (10, 'Arcane Comet', 'Sorcery');
insert into RUNES (RUNE_ID, RUNE_NAME, RUNE_TREE) values (11, 'Phase Rush', 'Sorcery');
insert into RUNES (RUNE_ID, RUNE_NAME, RUNE_TREE) values (12, 'Grasp of the Undying', 'Resolve');
insert into RUNES (RUNE_ID, RUNE_NAME, RUNE_TREE) values (13, 'Aftershock', 'Resolve');
insert into RUNES (RUNE_ID, RUNE_NAME, RUNE_TREE) values (14, 'Guardian', 'Resolve');
insert into RUNES (RUNE_ID, RUNE_NAME, RUNE_TREE) values (15, 'Glacial Augment', 'Inspiration');
insert into RUNES (RUNE_ID, RUNE_NAME, RUNE_TREE) values (16, 'Unsealed Spellbook', 'Inspiration');
insert into RUNES (RUNE_ID, RUNE_NAME, RUNE_TREE) values (17, 'First Strike', 'Inspiration');
#Item table Insertions
insert into ITEMS (ITEM_ID, ITEM_NAME) values (1, 'Cull');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (2, 'Dark Seal');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (3, 'Dorans Blade');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (4, 'Dorans Ring');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (5, 'Dorans Shield');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (6, 'Emberknife');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (7, 'Guardians Blade');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (8, 'Guardians Hammer');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (9, 'Guardians Horn');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (10, 'Guardians Orb');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (11, 'Hailblade');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (12, 'Obsidian Edge');#spellbook
insert into ITEMS (ITEM_ID, ITEM_NAME) values (13, 'Relic Shield');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (14, 'Spectral Sickle');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (15, 'Spellthiefs Edge');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (16, 'Steel Shoulderguards');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (17, 'Tear of the Goddess');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (18, 'Control Ward');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (19, 'Corrupting Potion');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (20, 'Elixir of Iron');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (21, 'Elixir of Sorcery');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (22, 'Elixir of Wrath');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (23, 'Health Potion');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (24, 'Your Cut');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (25, 'Commencing Stopwatch');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (26, 'Minion Dematerializer');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (27, 'Perfectly Timed Stopwatch');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (28, 'Slightly Magical Boots');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (29, 'Total Biscuit of Everlasting Will');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (30, 'Berserkers Greaves');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (31, 'Boots');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (32, 'Boots of Swiftness');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (33, 'Ionian Boots of Lucidity');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (34, 'Mercurys Treads');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (35, 'Mobility Boots');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (36, 'Plated Steelcaps');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (37, 'Sorcerers Shoes');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (38, 'Amplifying Tome');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (39, 'BF Sword');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (40, 'Blasting Wand');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (41, 'Broken Stopwatch');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (42, 'Cloak of Agility');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (43, 'Cloth Armor');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (44, 'Dagger');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (45, 'Faerie Charm');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (46, 'Long Sword');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (47, 'Needlessly Large Rod');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (48, 'Null-Magic Mantle');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (49, 'Pickaxe');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (50, 'Rejuvenation Bead');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (51, 'Ruby Crystal');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (52, 'Sapphire Crystal');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (53, 'Sheen');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (54, 'Stopwatch');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (55, 'Aegis of the Legion');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (56, 'Aether Wisp');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (57, 'Bamis Cinder');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (58, 'Bandleglass Mirror');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (59, 'Blighting Jewel');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (60, 'Bramble Vest');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (61, 'Caulfields Warhammer');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (62, 'Chain Vest');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (63, 'Crystalline Bracer');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (64, 'Executioners Calling');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (65, 'Fiendish Codex');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (66, 'Forbidden Idol');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (67, 'Frostfang');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (68, 'Giants Belt');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (69, 'Glacial Buckler');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (70, 'Harrowing Crescent');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (71, 'Hearthbound Axe');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (72, 'Hexdrinker');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (73, 'Hextech Alternator');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (74, 'Ironspike Whip');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (75, 'Kindlegem');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (76, 'Kircheis Shard');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (77, 'Last Whisper');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (78, 'Leeching Leer');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (79, 'Lost Chapter');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (80, 'Negatron Cloak');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (81, 'Noonquiver');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (82, 'Oblivion Orb');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (83, 'Phage');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (84, 'Quicksilver Sash');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (85, 'RageKnife');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (86, 'Recurve Bow');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (87, 'Runesteel Spaulders');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (88, 'Seekers Armguard');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (89, 'Serrated Dirk');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (90, 'Spectres Cowl');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (91, 'Targons Buckler');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (92, 'Tiamat');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (93, 'Vampiric Scepter');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (94, 'Verdant Barrier');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (95, 'Wardens Mail');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (96, 'Watchful Wardstone');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (97, 'Winged Moonplate');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (98, 'Zeal');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (99, 'Abyssal Mask');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (100, 'Anathemas Chains');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (101, 'Archangels Staff');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (102, 'Ardent Censer');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (103, 'Axiom Arc');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (104, 'Banshees Veil');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (105, 'Black Cleaver');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (106, 'Black Mist Scythe');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (107, 'Blade of the Ruined King');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (108, 'Bloodthirster');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (109, 'Bulwark of the Mountain');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (110, 'Chempunk Chainsword');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (111, 'Chemtech Putrifier');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (112, 'Cosmic Drive');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (113, 'Dead Mans Plate');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (114, 'Deaths Dance');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (115, 'Demonic Embrace');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (116, 'Edge of Night');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (117, 'Essence Reaver');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (118, 'Fimbulwinter');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (119, 'Force of Nature');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (120, 'Frozen Heart');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (121, 'Gargoyle Stoneplate');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (122, 'Guardian Angel');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (123, 'Guinsoos Rageblade');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (124, 'Horizon Focus');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (125, 'Hullbreaker');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (126, 'Infinity Edge');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (127, 'Knights Vow');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (128, 'Lich Bane');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (129, 'Lord Dominiks Regards');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (130, 'Manamune');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (131, 'Maw of Malmortius');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (132, 'Mejais Soulstealer');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (133, 'Mercurial Scimitar');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (134, 'Mikaels Blessing');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (135, 'Morellonomicon');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (136, 'Mortal Reminder');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (137, 'Muramana');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (138, 'Nashors Tooth');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (139, 'Navori Quickblades');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (140, 'Pauldrons of Whiterock');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (141, 'Phantom Dancer');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (142, 'Rabadons Deathcap');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (143, 'Randuins Omen');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (144, 'Rapid Firecannon');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (145, 'Ravenous Hydra');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (146, 'Redemption');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (147, 'Runaans Hurricane');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (148, 'Rylais Crystal Scepter');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (149, 'Seraphs Embrace');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (150, 'Serpents Fang');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (151, 'Seryldas Grudge');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (152, 'Shadowflame');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (153, 'Shard of True Ice');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (154, 'Silvermere Dawn');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (155, 'Spirit Visage');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (156, 'Staff of Flowing Water');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (157, 'Steraks Gage');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (158, 'Stormrazor');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (159, 'The Collector');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (160, 'Thornmail');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (161, 'Titanic Hydra');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (162, 'Umbral Glaive');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (163, 'Vigilant Wardstone');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (164, 'Void Staff');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (165, 'Warmogs Armor');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (166, 'Winters Approach');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (167, 'Wits End');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (168, 'Youmuus Ghostblade');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (169, 'Zekes Convergence');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (170, 'Crown of the Shattered Queen');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (171, 'Divine Sunderer');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (172, 'Duskblade of Draktharr');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (173, 'Eclipse');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (174, 'Evenshroud');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (175, 'Everfrost');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (176, 'Frostfire Gauntlet');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (177, 'Galeforce');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (178, 'Goredrinker');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (179, 'Hextech Rocketbelt');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (180, 'Immortal Shieldbow');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (181, 'Imperial Mandate');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (182, 'Kraken Slayer');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (183, 'Liandrys Anguish');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (184, 'Locket of the Iron Solari');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (185, 'Ludens Tempest');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (186, 'Moonstone Renewer');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (187, 'Night Harvester');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (188, 'Prowlers Claw');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (189, 'Riftmaker');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (190, 'Shurelyas Battlesong');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (191, 'Stridebreaker');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (192, 'Sunfire Aegis');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (193, 'Trinity Force');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (194, 'Turbo Chemtank');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (195, 'Bloodward');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (196, 'Caesura');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (197, 'Ceaseless Hunger');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (198, 'Deicide');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (199, 'Draktharr Shadowcarver');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (200, 'Dreamshatter');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (201, 'Equinox');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (202, 'Eternal Winter');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (203, 'Eye of Luden');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (204, 'Forgefire Crest');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (205, 'Icathias Curse');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (206, 'Infinity Force');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (207, 'Liandrys Lament');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (208, 'Reliquary of the Golden Dawn');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (209, 'Rimeforged Grasp');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (210, 'Sandshrikes Claw');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (211, 'Seat of Command');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (212, 'Shurelyas Requiem');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (213, 'Starcaster');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (214, 'Syzyhy');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (215, 'Turbocharged Hexperiment');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (216, 'Typhoon');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (217, 'Upgraded Aeropack');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (218, 'Vespertide');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (219, 'Wyrmfallen Sacrifice');
insert into ITEMS (ITEM_ID, ITEM_NAME) values (220, 'Black Spear');
#Champ Table Insertions
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (1, 'Aatrox', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (2, 'Ahri', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (3, 'Akali', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (4, 'Akshan', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (5, 'Alistar', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (6, 'Amumu', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (7, 'Anivia', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (8, 'Annie', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (9, 'Aphelios', 'Bottom');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (10, 'Ashe', 'Bottom');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (11, 'Aurelion Sol', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (12, 'Azir', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (13, 'Bard', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (14, 'Blitzcrank', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (15, 'Brand', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (16, 'Braum', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (17, 'Caitlyn', 'Bottom');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (18, 'Camille', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (19, 'Cassiopeia', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (20, 'Chogath', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (21, 'Corki', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (22, 'Darius', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (23, 'Diana', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (24, 'Dr Mundo', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (25, 'Draven', 'Bottom');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (26, 'Ekko', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (27, 'Elise', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (28, 'Evelynn', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (29, 'Ezreal', 'Bottom');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (30, 'Fiddlesticks', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (31, 'Fiora', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (32, 'Fizz', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (33, 'Galio', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (34, 'Gangplank', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (35, 'Garen', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (36, 'Gnar', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (37, 'Gragas', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (38, 'Graves', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (39, 'Gwen', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (40, 'Hecarim', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (41, 'Heimerdinger', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (42, 'Illaoi', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (43, 'Irelia', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (44, 'Ivern', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (45, 'Janna', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (46, 'Jarvan IV', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (47, 'Jax', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (48, 'Jayce', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (49, 'Jhin', 'Bottom');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (50, 'Jinx', 'Bottom');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (51, 'Kaisa', 'Bottom');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (52, 'Kalista', 'Bottom');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (53, 'Karma', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (54, 'Karthus', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (55, 'Kassadin', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (56, 'Katarina', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (57, 'Kayle', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (58, 'Kayn', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (59, 'Kennen', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (60, 'Khazix', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (61, 'Kindred', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (62, 'Kled', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (63, 'KogMaw', 'Bot');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (64, 'LeBlanc', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (65, 'Lee Sin', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (66, 'Leona', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (67, 'Lilia', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (68, 'Lissandra', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (69, 'Lucian', 'Bottom');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (70, 'Lulu', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (71, 'Lux', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (72, 'Malphite', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (73, 'Malzahar', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (74, 'Maokai', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (75, 'Master Yi', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (76, 'Miss Fortune', 'Bottom');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (77, 'Mordekaiser', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (78, 'Morgana', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (79, 'Nami', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (80, 'Nasus', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (81, 'Nautilus', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (82, 'Neeko', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (83, 'Nidalee', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (84, 'Nocturne', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (85, 'Nunu and Willump', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (86, 'Olaf', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (87, 'Orianna', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (88, 'Ornn', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (89, 'Pantheon', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (90, 'Poppy', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (91, 'Pyke', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (92, 'Qiyana', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (93, 'Quinn', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (94, 'Rakan', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (95, 'Rammus', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (96, 'RekSai', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (97, 'Rell', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (98, 'Renekton', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (99, 'Rengar', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (100, 'Riven', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (101, 'Rumble', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (102, 'Ryze', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (103, 'Samira', 'Bot');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (104, 'Sejuani', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (105, 'Senna', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (106, 'Seraphine', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (107, 'Sett', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (108, 'Shaco', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (109, 'Shen', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (110, 'Shyvana', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (111, 'Singed', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (112, 'Sion', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (113, 'Sivir', 'Bottom');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (114, 'Skarner', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (115, 'Sona', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (116, 'Soraka', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (117, 'Swain', 'Suport');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (118, 'Sylas', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (119, 'Syndra', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (120, 'Tahm Kench', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (121, 'Taliyah', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (122, 'Talon', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (123, 'Taric', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (124, 'Teemo', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (125, 'Thresh', 'Suppor');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (126, 'Tristana', 'Bottom');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (127, 'Trundle', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (128, 'Tryndamere', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (129, 'Twisted Fate', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (130, 'Twitch', 'Bottom');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (131, 'Udyr', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (132, 'Urgot', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (133, 'Varus', 'Bottom');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (134, 'Vayne', 'Bottom');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (135, 'Veigar', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (136, 'VelKoz', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (137, 'Vex', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (138, 'Vi', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (139, 'Viego', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (140, 'Viktor', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (141, 'Vladimir', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (142, 'Volibear', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (143, 'Warwick', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (144, 'Wukong', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (145, 'Xayah', 'Bottom');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (146, 'Xerath', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (147, 'Xin Zhao', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (148, 'Yasuo', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (149, 'Yone', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (150, 'Yorick', 'Top');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (151, 'Yuumi', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (152, 'Zac', 'Jungle');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (153, 'Zed', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (154, 'Ziggs', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (155, 'Zilean', 'Support');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (156, 'Zoe', 'Mid');
insert into CHAMPIONS (CHAMP_ID, CHAMP_NAME, CHAMP_ROLE) values (157, 'Zyra', 'Support');


#insert Per_game_performance


INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (1, 1, 1, 14, 8, 11, 15.9, 18, ‘Top’, 59, 1, 1);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (2, 1, 2, 16, 5, 7, 18.2, 18, ‘Jungle’, 60, 2, 2);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (3, 1, 3, 8, 11, 7, 14.5, 16, ‘Mid’, 69, 3, 3);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (4, 1, 4, 5, 8, 11, 14.3, 17, 'Bottom', 29, 4, 4);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (5, 1, 5, 2, 13, 21, 11.3, 16, ‘Support’, 116, 5, 5);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (6, 1, 6, 5, 13, 5, 12.9, 17, ‘Top’, 3, 6, 6);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (7, 1, 7, 16, 7, 6, 21.2, 18, ‘Jungle’, 61, 7, 7);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (8, 1, 8, 10, 11, 12, 26.6, 18, ‘Mid’, 19, 8, 8);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (9, 1, 9, 10, 9, 8, 16.9, 17, 'Bottom', 50, 9, 9);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (10, 1, 10, 4, 5, 10, 9.5, 16, ‘Support’, 14, 10, 10);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (11, 2, 11, 5, 12, 6, 9.7, 14, ‘Top’, 22, 11, 11);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (12, 2, 12, 7, 7, 16, 11.9, 15, ‘Jungle’, 121, 12, 12);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (13, 2, 13, 9, 9, 5, 13.5, 16, ‘Mid’, 48, 13, 13);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (14, 2, 14, 12, 6, 11, 15.6, 16, 'Bottom', 126, 14, 14);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (15, 2, 15, 2, 18, 19, 8.6, 14, ‘Support’, 13, 15, 15);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (16, 2, 16, 9, 5, 5, 14.9, 17, ‘Top’, 31, 16, 16);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (17, 2, 17, 18, 9, 8, 15.7, 16, ‘Jungle’, 147, 17, 17);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (18, 2, 18, 8, 6, 8, 14.1, 17, ‘Mid’, 140, 18, 18);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (19, 2, 19, 2, 7, 9, 10.9, 14, 'Bottom', 50, 19, 19);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (20, 2, 20, 5, 8, 12, 10.3, 15, ‘Support’, 151, 20, 20);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (21, 3, 21, 5, 9, 4, 10.6, 15, ‘Top’, 47, 21, 21);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (22, 3, 22, 13, 7, 12, 14.1, 15, ‘Jungle’, 122, 22, 22);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (23, 3, 23, 10, 7, 10, 12.7, 15, ‘Mid’, 119, 23, 23);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (24, 3, 14, 8, 8, 12, 11.7, 14, 'Bottom', 29, 24, 24);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (25, 3, 24, 5, 8, 15, 8.4, 12, ‘Support’, 81, 25, 25);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (26, 3, 11, 10, 7, 14, 13.3, 17, ‘Top’, 20, 26, 26);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (27, 3, 25, 17, 7, 6, 18.1, 17, ‘Jungle’, 61, 27, 27);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (28, 3, 13, 3, 8, 11, 11, 16, ‘Mid’, 140, 28, 28);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (29, 3, 26, 6, 7, 12, 11.5, 15, 'Bottom', 49,m 29, 29);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (30, 3, 27, 3, 12, 11, 9.2, 13, ‘Support’, 7, 30, 30);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (31, 4, 28, 5, 12, 8, 11.9, 16, NULL, 19, 31, 31);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (32, 4, 29, 8, 7, 9, 13.7, 17, NULL, 43, 32, 32);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (33, 4, 30, 8, 11, 12, 12.7, 17, NULL, 108, 33, 33);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (34, 4, 31, 6, 1, 8, 12.3, 17, NULL, 13, 34, 34);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (35, 4, 32, 2, 7, 18, 11.3, 17, NULL, 83, 35, 35);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (36, 4, 33, 9, 3, 15, 13.4, 18, NULL, 35, 36, 36);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (37, 4, 34, 12, 5, 22, 15.1, 18, NULL, 41, 37, 37);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (38, 4, 35, 4, 4, 31, 13.3, 18, NULL, 10, 38, 38);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (39, 4, 36, 13, , 5, 13, 18, 153, 39, 39);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (40, 4, 8, 12, 9, 13, 14.5, 18, NULL, 42, 40, 40);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (41, 5, 37, 4, 6, 8, 9.7, 14, ‘Top’, 18, 41, 41);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (42, 5, 38, 9, 0, 5, 10.9, 14, ‘Jungle’, 67, 42, 42);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (43, 5, 39, 12, 0, 4, 10, 13, ‘Mid’, 3, 43, 43);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (44, 5, 40, 6, 3, 5, 11.1, 13 , 'Bottom', 103, 44, 44);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (45, 5, 41, 1, 2, 17, 7.5, 11, ‘Support, 78, 45, 45);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (46, 5, 42, 4, 6, 1, 8.5, 13, ‘Top’, 100, 46, 46);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (47, 5, 43, 3, 5, 4, 8.7, 13, ‘Jungle’, 27, 47, 47);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (48, 5, 44, 1, 2, 0, 6.2, 11, ‘Mid’, 149, 48, 48);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (49, 5, 45, 3, 10, 1, 8.1, 10, 'Bottom', 25, 49, 49);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (50, 5, 46, 0, 10, 3, 4.9, 9, ‘Support’, 81, 50, 50);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (51, 6, 47, 1, 2, 2, 6.8, 12, ‘Top’, 24, 51, 51);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (52, 6, 48, 2, 6, 3, 7, 11, ‘Jungle’, 152, 52, 52);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (53, 6, 49, 6, 4, 4, 8.6, 12, ‘Mid’, 65, 53, 53);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (54, 6, 50, 4, 5, 1, 7.8, 10, 'Bottom', 154, 54, 54);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (55, 6, 51, 0, 6, 7, 5.9, 10, ‘Support’, 82, 55, 55);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (56, 6, 46, 4, 0, 1, 8.2, 13, ‘Top’, 132, 56, 56);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (57, 6, 52, 3, 3, 7, 8.6, 12, ‘Jungle’, 139, 57, 57);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (58, 6, 53, 7, 2, 4, 9.9, 14 , ‘Mid’, 118, 58, 58);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (59, 6, 54, 5, 4, 7, 9.7, 12, 'Bottom', 9, 59, 59);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (60, 6, 55, 4, 4, 10, 6.8, 10, ‘Support’, 125, 60, 60);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (61, 7, 56, 1, 7, 0, 9.3, 14, ‘Top’, 100, 61, 61);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (62, 7, 57, 1, 5, 2, 9.2, 14, ‘Jungle’, 26, 62, 62);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (63, 7, 58, 5, 5, 2, 10, 13, ‘Mid’, 92, 63, 63);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (64, 7, 47, 3, 5, 3, 10.7, 14, 'Bottom', 25, 64, 64);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (65, 7, 59, 1, 11, 5, 6.4, 11, ‘Support’, 82, 65, 65);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (66, 7, 60, 2, 1, 6, 12.5, 16, ‘Top’, 1, 66, 66);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (67, 7, 61, 8, 4, 8, 12.7, 16, ‘Jungle’, 139, 67, 67);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (68, 7, 62, 12, 2, 9, 13.6, 17, ‘Mid’, 56, 68, 68);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (69, 7, 63, 8, 2, 7, 16.1, 16, 'Bottom', 17, 69, 69);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (70, 7, 64, 3, 2, 16, 9, 13, ‘Support’, 125, 70, 70);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (71, 7, 65, 4, 4, 4, 10.7, 14, ‘Top’, 69, 71, 71);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (72, 8, 66, 4, 0, 18, 10, 13, ‘Jungle’, 152, 72, 72);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (73, 8, 67, 13, 3, 3, 12.8, 14, ‘Mid’, 3, 73, 73);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (74, 8, 68, 5, 4, 18, 9, 12, 'Bottom', 50, 74, 74);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (75, 8, 69, 1, 6, 12, 5.8, 10, ‘Support’, 125, 75, 75);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (76, 8, 70, 4, 6, 1, 8.2, 13, ‘Top’, 48, 76, 76);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (77, 8, 71, 2, 6, 8, 7.1, 11, ‘Jungle’, 38, 77, 77);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (78, 8, 72, 3, 5, 4, 8.5, 11, ‘Mid’, 129, 78, 78);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (79, 8, 63, 6, 3, 3, 10.6, 12, 'Bottom', 17, 79, 79);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (80, 8, 73, 2, 7, 7, 5.7, 8, ‘Support’, 14, 80, 80);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (81, 8, 74, 2, 7, 16, 10.1, 15, ‘Top’, 109, 81, 81);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (82, 9, 75, 13, 5, 8, 14.3, 17, ‘Jungle’, 28, 82, 82);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (83, 9, 76, 5, 13, 9, 13, 16, ‘Mid’, 148, 83, 83);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (84, 9, 77, 18, 6, 3, 19.9, 18, 'Bottom', 49, 84, 84);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (85, 9, 78, 2, 8, 19, 8.9, 15, ‘Support’, 81, 85, 85);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (86, 9, 79, 3, 8, 11, 12.2, 16, ‘Top’, 65, 86, 86);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (87, 9, 80, 7, 7, 19, 13.2, 17, ‘Jungle’, 40, 87, 87);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (88, 9, 81, 19, 6, 13, 20.3, 18, ‘Mid’, 135, 88, 88);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (89, 9, 82, 9, 11, 10, 15.6, 17, 'Bottom', 29, 89, 89);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (90, 9, 83, 1, 8, 27, 8.7, 15, ‘Support’, 13, 90, 90);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (91, 9, 84, 0, 2, 0, 4.6, 10, ‘Top’, 109, 91, 91);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (92, 10, 85, 3, 3, 0, 5.5, 10, ‘Jungle’, 86, 92, 92);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (93, 10, 86, 1, 4, 1, 4.9, 10, ‘Mid’, 118, 93, 93);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (94, 10, 87, 0, 2, 0, 4.7, 9, 'Bottom', 103, 94, 94);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (95, 10, 88, 1, 5, 1, 4.3, 8, ‘Support’, 97, 95, 95);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (96, 10, 89, 2, 0, 0, 5, 10, ‘Top’, 144, 96, 96);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (97, 10, 90, 5, 3, 7, 6.7, 10, ‘Jungle’, 147, 97, 97);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (98, 10, 91, 7, 1, 4, 8, 12, ‘Mid’, 140, 98, 98);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (99, 10, 92, 1, 0, 4, 6.3, 10, 'Bottom', 154, 99, 99);
INSERT INTO PER_GAME_PERFORMANCE (PERFORMANCE_ID, GAME_ID, PLAYER_ID, PLAYER_KILLS, PLAYER_DEATHS, PLAYER_ASSISTS, PLAYER_GOLD, PLAYER_LEVEL, PLAYER_ROLE, CHAMP_ID, RUNE_ID, PLAYERBUILD_ID) values (100, 10, 93, 1, 1, 7, 4.2, 8, ‘Support’, 5, 100, 100);




ALTER TABLE PLAYER
ADD FOREIGN KEY (ORG_ID) REFERENCES ORGANIZATIONS(ORG_ID);
ALTER TABLE STREAMERS
ADD FOREIGN KEY (ORG_ID) REFERENCES ORGANIZATIONS(ORG_ID),
ADD FOREIGN KEY (PLAYER_ID) REFERENCES PLAYER(PLAYER_ID);
ALTER TABLE PRO_PLAYERS
ADD FOREIGN KEY (ORG_ID) REFERENCES ORGANIZATIONS(ORG_ID),
ADD FOREIGN KEY (PLAYER_ID) REFERENCES PLAYER(PLAYER_ID);
ALTER TABLE TEAM_ASSIGN
ADD FOREIGN KEY (GAME_ID) REFERENCES GAME(GAME_ID),
ADD FOREIGN KEY (PLAYER_ID) REFERENCES PLAYER(PLAYER_ID),
ADD FOREIGN KEY (TEAM_ID) REFERENCES TEAMS(TEAM_ID);
ALTER TABLE PER_GAME_PERFORMANCE
ADD FOREIGN KEY (GAME_ID) REFERENCES GAME(GAME_ID),
ADD FOREIGN KEY (PLAYER_ID) REFERENCES PLAYER(PLAYER_ID),
ADD FOREIGN KEY (CHAMP_ID) REFERENCES CHAMPIONS(CHAMP_ID),
ADD FOREIGN KEY (RUNE_ID) REFERENCES RUNES(RUNE_ID),
ADD FOREIGN KEY (PLAYERBUILD_ID) REFERENCES PLAYER_ITEMS(PLAYERBUILD_ID);
ALTER TABLE PLAYER_ITEMS
ADD FOREIGN KEY (PERFORMANCE_ID) REFERENCES PER_GAME_PERFORMANCE(PERFORMANCE_ID);


CREATE VIEW StatsLeaderboard AS
SELECT AVG((PLAYER_KILLS+PLAYER_ASSISTS)/PLAYER_DEATHS)
FROM PER_GAME_PERFORMANCE
GROUP BY PLAYER_ID
DESC LIMIT 10;
