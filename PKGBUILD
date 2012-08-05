pkgname=boost.log
pkgrel=1
pkgver=1.0
pkgdesc="Boost logging system (proposal)"
arch=('i686' 'x86_64')
url='https://github.com/arcanis/boost.log/'
license=('Boost Software License')

build() {

    install -d $pkgdir/usr/include/arcanis $pkgdir/usr/include/boost
    cp -dPr --no-preserve=ownership $startdir/boost $pkgdir/usr/include/arcanis/boost
    ln -s /usr/include/arcanis/boost/log $pkgdir/usr/include/boost/log

}
