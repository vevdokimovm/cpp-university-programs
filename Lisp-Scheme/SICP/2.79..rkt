#lang racket

(define (equ? z1 z2) (apply-generic 'equ? z1 z2))

(put 'equ? '(scheme-number scheme-number) =)
(put 'equ? '(rational rational)
     (lambda (r1 r2)
       (let ((a (* (numer r1) (denom r2)))
             (b (* (numer r2) (denom r1))))
         (if (= a b)
             #t
             #f))))
(put 'equ? '(rectangular rectangular)
     (lambda (c1 c2)
       (if (and (= (real-part c1) (real-part c2))
                (= (imag-part c1) (imag-part c2)))
           #t
           #f)))

