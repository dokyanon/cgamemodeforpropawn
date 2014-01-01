/*
MySQL Data Transfer
Source Host: localhost
Source Database: db_test
Target Host: localhost
Target Database: db_test
Date: 02.01.2014 3:18:42
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for users
-- ----------------------------
DROP TABLE IF EXISTS `users`;
CREATE TABLE `users` (
  `ID` int(10) NOT NULL DEFAULT '0',
  `Name` varchar(24) NOT NULL,
  `Password` varchar(64) NOT NULL,
  `Level` int(3) NOT NULL,
  `Money` int(6) NOT NULL,
  `Skin` int(2) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
