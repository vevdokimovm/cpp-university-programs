#lang racket

(define (install-deriv-product-package)
  ;; Internal defenitions
  (define (deriv-product product var)
    (make-sum
     (make-product (multiplier product)
                   (deriv (multiplicand product) var))
     (make-product (multiplicand product)
                   (deriv (multiplier product) var))))
  (define (make-product m1 m2)
    (cond ((or (=number? m1 0) (=number? m2 0)) 0)
          ((=number? m1 1) m2)
          ((=number? m2 1) m1)
          ((and (number? m1) (number? m2)) (* m1 m2))
          (else (list '* m1 m2))))
  
  
  ;; System's interface
  (put 'deriv' '* deriv-p)
  (put 'make-product '* make-product)
  (put 'multiplier '*
       (lambda (p) (cadr p)))
  (put 'multiplicand '*
       (lambda (p) (caddr p)))
  'done)


;; Sum package
(define (install-deriv-sum-package)
  ;; Internal defenitions
  (define (deriv-sum sum var)
    (make-sum (deriv (addend sum) var)
              (deriv (augend sum) var)))
  (define (addend s) (cadr s))
  (define (augend s) (caddr s))


  ;; System's inerface
  (put 'deriv '+ deriv-s)
  (put 'addend '+ addend)
  (put 'augend '+ augend)
  (put 'make-sum '+
       (lambda  (a1 a2)
         (cond ((=number? a1 0) a2)
               ((=number? a2 0) a1)
               ((and (number? a1) (number? a2)) (+ a1 a2))
               (else (list '+ a1 a2)))))
  'done)


;; Power package
(define (install-deriv-power-package)
  ;; Internal defenitions
  (define (deriv-power exp var)
    ((get 'make-product '* )
     ((get 'make-product '*) (exponent exp)
                             (make-exponentiation (base exp)
                                                  (- (exponent exp) 1)))
     (derive (base exp) var)))
  (define (base e) (cadr e))
  (define (exponent e) (caddr e))


  ;; System interface
  (put 'deriv '** deriv-power)
  (put 'make-exponentiation '**
       (lambda (base exponent)
         (cond ((=number? base 1) 1)
               ((=number? exponent 0) 1)
               ((and (number? base) (number? exponent)) (fast-exp base exponent))
               ((else (list '** base exponent))))))