<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

//  echo 'DB Name: ' . getenv('MYSQL_DATABASE') . '<br>';
//  echo 'DB User: ' . getenv('MYSQL_USER') . '<br>';
//  echo 'DB Password: ' . getenv('MYSQL_PASSWORD') . '<br>';
//  echo 'DB Host: ' . getenv('WP_DB_HOST') . '<br>';


// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
// define( 'DB_NAME', 'wordpress');
define('DB_NAME', getenv('MYSQL_DATABASE'));

/** MySQL database username */
// define( 'DB_USER', 'toto');
define('DB_USER', getenv('MYSQL_USER'));

/** MySQL database password */
// define( 'DB_PASSWORD', 'toto'); 
define('DB_PASSWORD', getenv('MYSQL_PASSWORD'));

/** MySQL hostname */
// define( 'DB_HOST', 'mariadb:3306');
define('DB_HOST', getenv('WP_DB_HOST'));

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8');

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '');

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '(A[8%>IBE%u:Rg6R#*<:~7mNm>og?>vX0lXxn.-Cp`4c(oe-&).8a&optWdE+hn)');
define('SECURE_AUTH_KEY',  'dH!HYt99-9+u+>^IwKg6L+O{9%_lI0DrR-CS}*k_:)a{J$hz*>c@8vx`*<vL?@/N');
define('LOGGED_IN_KEY',    'ek1Zu2$/ds+c9Mmd0?o^dlu.}cq+SRmoVC`1Z7RiFHGZ~iG&[$@oPGt%!*1wj;|P');
define('NONCE_KEY',        'Um,`(Ss?V(W/~AHAS*yio<+h%Ct>GVh]AWI2i;*h8LI-B9s&]Z?#QbQuJn|i3[__');
define('AUTH_SALT',        ';K+91_HGzwrDsYB06#32~-6[;:^ 3,0OiX]f3Q7lAc2v]aHtSm8q# >x?j28_)fD');
define('SECURE_AUTH_SALT', '[(<w]v>/vcb?>7#=w/KJcP@RlOUOMU]g9pB6I#M4V i8.KX%~_mnp=fNbDDr]gb{');
define('LOGGED_IN_SALT',   '.??T/;<.5e%K$Vfb~R%eF]W*ytV_PD@wmdVvdRD)^vQL|?*!L>*u*E!~ZZGnh<ZG');
define('NONCE_SALT',       'JPNLG@hSi} ,$_g_nVi:&oA,9D&|NwiH+)-aunZ;n?20][B6G(n&jS ^tNg-i.%3');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

// If we're behind a proxy server and using HTTPS, we need to alert Wordpress of that fact
// see also http://codex.wordpress.org/Administration_Over_SSL#Using_a_Reverse_Proxy
// if (isset($_SERVER['HTTP_X_FORWARDED_PROTO']) && $_SERVER['HTTP_X_FORWARDED_PROTO'] === 'https') {
// 	$_SERVER['HTTPS'] = 'on';
// }

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
