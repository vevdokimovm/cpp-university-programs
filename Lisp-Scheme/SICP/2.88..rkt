#lang racket

(define (change-sign x) (apply-generic 'change-sing x))

(define (sub-poly p1 p2)
  (if (same-variable? (variable p1) (variable p2))
      (make-poly (variable p1)
                 (sub-terms (term-list p1)
                            (change-sign (term-list p2))))
      (error "Многочлены от разных переменных -- SUB-POLY"
             (list p1 p2))))

(define (change-sign-poly termlist)
  (let ((term (first-term termlist)))
    (cond ((null? termlist) the-empty-termlist)
          (else (adjoin-term (make-term (order term)
                                 (change-sign (coeff term)))
                      (change-sign (cdr termlist)))))))

(put 'change-sign '(polynomial) change-sign-poly)
(put 'change-sign '(scheme-number)
     (lambda (x) (tag (- x))))
(put 'change-sign '(real)
     (lambda (r) (tag (- r))))
(put 'change-sign '(rational)
     (lambda (fraction) (make-rational (change-sign (numer fraction))
                                       (denom fraction))))