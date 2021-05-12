# DB
CREATE DATABASE test_db;
use test_db;

select * from test_db;

-- -----------------------------------------------------
-- Table `mydb`.`영화`
-- -----------------------------------------------------
drop table `영화`;
CREATE TABLE IF NOT EXISTS `test_db`.`영화` (
  `영화코드번호` INT NOT NULL,
  `제목` VARCHAR(45) NULL,
  `제작년도` INT NULL,
  `제작국가` VARCHAR(45) NULL,
  `상영시간` INT NULL,
  `개봉일자` DATE NULL,
  `제작사` VARCHAR(45) NULL,
  `배급사` VARCHAR(45) NULL,
  PRIMARY KEY (`영화코드번호`))
ENGINE = InnoDB;

insert into `test_db`.`영화` values(1, 'title1', 2019, 'Korea', '120', '2000-12-31', 'mymovie', 'showtime');

select `제목`, `제작국가`, `개봉일자`, `제작사`, `배급사` from `영화` where `제작년도` >= year(DATE_SUB(NOW(), Interval 3 year ));

SELECT year(DATE_SUB(NOW(), Interval 3 year ));

SELECT TIMESTAMPDIFF(YEAR, '2017-01-01', '2021-01-01');

-- -----------------------------------------------------
-- Table `mydb`.`감독`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `test_db`.`감독` (
  `등록번호` INT NOT NULL,
  `이름` VARCHAR(45) NULL,
  `성별` VARCHAR(45) Check(`성별` in('남', '여')) NULL,
  `출생일` DATE NULL,
  `출생지` VARCHAR(45) NULL,
  `학력사항` VARCHAR(45) NULL,
  PRIMARY KEY (`등록번호`))
ENGINE = InnoDB;

insert into `test_db`.`감독` values(2, '명감독', '남', '1990-01-01', 'Korea', '초졸');        

select * from `감독` where `이름` = '명감독' ;

drop table `감독이 존재하는 영화`;
create Table `감독이 존재하는 영화`(
	`영화코드번호` INT NOT NULL,
    `감독등록번호` INT,
    primary key(`영화코드번호`),
    foreign key(`영화코드번호`) references `영화` (`영화코드번호`),
    foreign key(`감독등록번호`) references `감독` (`등록번호`)
);

drop view `영화리스트`;

create view `영화_감독_view` as
(select `영화`.`영화코드번호`, `영화`.`제목`, `감독`.`등록번호`, `감독`.`이름` from `영화` 
natural join `감독` where `이름` = '명감독');

select * from `영화_감독_view`;


-- -----------------------------------------------------
-- Table `mydb`.`배우`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `test_db`.`배우` (
  `배우번호` INT NOT NULL,
  `생년월일` date NULL,
  `이름` VARCHAR(45) NULL,
  `성별` VARCHAR(10) Check(`성별` in('남', '여')) NULL,
  `출생지` VARCHAR(45) NULL,
  `키` Double NULL,
  `몸무게` Double NULL,
  `혈액형` VARCHAR(45) Check(`혈액형` in('A', 'B', 'AB', 'O')) NULL,
  PRIMARY KEY (`배우번호`))
ENGINE = InnoDB;

insert into `test_db`.`배우` values(2, '2000-12-31', 'actor2', '여', 'Korea', 150.0, 150.1, 'A');

select `이름`, `성별`, `출생지` from `배우`;

-- -----------------------------------------------------
-- Table `mydb`.`장르`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`장르` (
  `장르코드` INT NOT NULL,
  `장르명` VARCHAR(45) NULL,
  PRIMARY KEY (`장르코드`))
ENGINE = InnoDB;

USE `test_db` ;

-- -----------------------------------------------------
-- Table `test_db`.`testtable`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `test_db`.`testtable` (
  `name` VARCHAR(45) NULL DEFAULT NULL,
  `age` INT NULL DEFAULT NULL,
  `anyNum` INT NULL DEFAULT NULL)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
