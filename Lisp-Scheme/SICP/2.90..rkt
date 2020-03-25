#lang racket

(define (first-term x) (apply-generic 'first-term x))
(define (rest-terms x) (apply-generic 'rest-terms x))
(define (empty-termlist? term-list) (apply-generic 'empty-termlist? term-list))
(define (adjoin-term term term-list) (apply-generic 'adjoin-term term term-list))

;; Polynomial package
(define (install-polynomial-package)
  ;; Internal procedures
  (define (make-poly variable term-list)
    (cons variable term-list))
  (define (variable p) (car p))
  (define (term-list p) (cdr p))
  (define (add-poly p1 p2)
    (if (same-variable? (variable p1) (variable p2))
        (make-poly (variable p1)
                   (add-terms (term-list p1)
                              (term-list p2)))
        (error "Многочлены от разных переменных -- ADD-POLY"
               (list p1 p2))))

  ;; System interface
  (define (tag p) (attach-tag 'polynomial p))
  (put 'add '(polynomial polynomial)
       (lambda (p1 p2) (tag (add-poly p1 p2))))
  (put 'make 'polynomial
       (lambda (var terms) (tag (make-poly var terms))))
  'done)

;; Dense polynomial package
(define (install-polynomial-dense-package)
  ;; Internal procedures
  (define (adjoin-term term term-list)
    (let ((cof (coeff term)))
      (if (=zero? cof)
          term-list
          (cons cof term-list))))
  (define (the-empty-termlist) '())
  (define (first-term term-list)
    (make-term (- (length term-list) 1)
               (car term-list)))
  (define (rest-terms term-list) (cdr term-list))
  (define (empty-termlist? term-list) (null? term-list))
  (define (make-term order coeff) (list order coeff))
  (define (order term) (car term))
  (define (coeff term) (cadr term))
  
  ;; System interface
  (define (tag x) (attach-tag 'dense x))
  (put 'adjoin-term '(dense) adjoin-term)
  (put 'the-empty-termlist '(dense) the-empty-termlist)
  (put 'first-term '(dense) first-term)
  (put 'rest-terms '(dense) rest-terms)
  (put 'empty-termlist? '(dense) empty-termlist?)
  (put 'order '(dense) order)
  (put 'coeff '(dense) coeff)
  (put 'make-term 'dense
       (lambda (x y) (tag (make-term x y))))
  'done)

;; Sparse polynomial package
(define (install-polynomial-sparse-package)
  ;; Internal procedures
  (define (ajoin-term term term-list)
    (if (=zero? (coeff term))
        term-list
        (cons term term-list)))
  (define (the-empty-termlist) '())
  (define (first-term term-list) (car term-list))
  (define (rest-terms term-list) (cdr term-list))
  (define (empty-termlist? term-list) (null? term-list))
  (define (make-term order coeff) (list order coeff))
  (define (order term) (car term))
  (define (coeff term) (cadr term))

  ;; System interface
  (define (tag x) (attach-tag 'sparse x))
  (put 'adjoin-term '(sparse) adjoin-term)
  (put 'the-empty-termlist '(sparse) the-empty-termlist)
  (put 'first-term '(sparse) first-term)
  (put 'rest-terms '(sparse) rest-terms)
  (put 'empty-termlist? '(sparse) empty-termlist?)
  (put 'make-term 'sparse
       (lambda (x y) (tag (make-term x y))))
  (put 'order '(sparse) order)
  (put 'coeff '(sparse) coeff)
  'done)